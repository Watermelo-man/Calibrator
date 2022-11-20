#pragma once
#include <iostream>
#include <stdint.h>

class Calibrator_ADC
{
private:
	uint32_t* ADCval; //recieved ADC values for calibration
	float* CALval; //final calibration values for all ranges in range
	float* RealVal;
	uint32_t ARRsize; // size of calibration array


	bool calibrationConfirm; //verification for end of calibretion sequence
	bool setValConfirm; //verification for end of setting values sequence

	uint32_t ADCrangemarking(uint32_t ADCval);
public:

	Calibrator_ADC(uint32_t ARRsize);//, float calLowPoint, float calHighPoint, uint32_t ADCLowrange, uint32_t ADCHighrange); //ARRsize - size of ADCval array
	//Calibrator_ADC(float step, float lowPoint, float highPoint); // step - iterrative step for range fron low to high 

	~Calibrator_ADC(); //do not forget to free memory from pointers

	bool setADCiterative(uint32_t CALval); //set ADC value one by one

	bool setADCarray(uint32_t* ADCvalarr, float* Realarr, uint32_t sizeADCarr, uint32_t sizeRealarr); //set ADC values with one ready array

	bool calibrate(); //make calibration coefficients array

	float transform(uint32_t ADCval); // transform specific input from ADC 
};


#include "Calibrator_ADC.h"
#include <math.h>



Calibrator_ADC::Calibrator_ADC(uint32_t ARRsize) //float calLowPoint, float calHighPoint, uint32_t ADCLowrange, uint32_t ADCHighrange)
{	

	this->ARRsize = ARRsize;

	///this->ADCstep = (this->ADCHighrange - this->ADCLowrange) / (this->ARRsize);

	

	this->ADCval = new uint32_t[ARRsize];
	this->CALval = new float[ARRsize];
	this->RealVal = new float[ARRsize];
	//this->calLowPoint = calLowPoint;
	//this->calHighPoint = calHighPoint;

	this->calibrationConfirm = false;
	this->setValConfirm = false;


}

uint32_t Calibrator_ADC::ADCrangemarking(uint32_t ADCval)
{
	int i = 0;
	while ( ADCval > this->ADCval[i])
		i++;
	return i;
}

Calibrator_ADC::~Calibrator_ADC()
{
	delete[] ADCval;
	delete[] CALval;
}

bool Calibrator_ADC::setADCarray(uint32_t* ADCvalarr, float* Realarr, uint32_t sizeADCarr, uint32_t sizeRealarr)
{
	if ((this->ARRsize != sizeADCarr) && (this->ARRsize != sizeRealarr))
		return false;
	for (int i = 0; i <= this->ARRsize - 1; i++)
	{
		this->ADCval[i] = ADCvalarr[i];
		this->RealVal[i] = Realarr[i];
	}
	this->setValConfirm = true;
	return true;
}

bool Calibrator_ADC::calibrate()
{
	if (this->setValConfirm == false)
		return false;
	
	std::cout << "CALval[i] \n";
	for (int i = 0; i <= this->ARRsize - 1; i++)
	{
		this->CALval[i] = ((float)this->ADCval[i]) / this->RealVal[i];

		std::cout << this->CALval[i] << " ";
		// проблема в пересчете из АЦП в то, что хочешь
	}
	std::cout << "\n";
	this->calibrationConfirm = true;
	return true;
}


float Calibrator_ADC::transform(uint32_t ADCval)
{
	if (calibrationConfirm == false)
		return 0.0f;
	int i = ADCrangemarking(ADCval);
	
	return  ADCval / CALval[i];

}
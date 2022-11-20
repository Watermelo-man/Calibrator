// Calibrator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Calibrator_ADC.h"
int main()
{
    int size;
    uint32_t* ADCArray;
    float* RealArray;
    float calLowPoint;
    float calHighPoint;
    uint32_t ADCLowrange;
    uint32_t ADCHighrange;





    std::cout << "Enter size of array\n";
    std::cin >> size;
    ADCArray = new uint32_t[size];
    RealArray = new float[size];

    std::cout << "Enter ADC array\n";
    for (int i = 0; i <= size - 1; i++)
    {
        std::cout << "Enter " << i << " element\n";
        std::cin >> ADCArray[i];
    }

    std::cout << "Enter desired aligned array \n";
    for (int i = 0; i <= size - 1; i++)
    {
        std::cout << "Enter " << i << " element\n";
        std::cin >> RealArray[i];
    }

    

 

    Calibrator_ADC *calibrate = new Calibrator_ADC(size);

    calibrate->setADCarray(ADCArray, RealArray,size, size);
    calibrate->calibrate();

    for (int i = 0; i <= size - 1; i++)
    {
        std::cout << ADCArray[i] << " ";
    }
    std::cout <<  "\n ";
    while (true)
    {
        std::cout << "Enter ADC in time\n ";
        uint32_t ADCval;
        std::cin >> ADCval;
        std::cout << calibrate->transform(ADCval) << "\n ";
    }

    std::cin;
    delete calibrate;


    
    delete[]RealArray;
    delete[]ADCArray;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

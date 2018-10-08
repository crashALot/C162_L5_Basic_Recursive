#include "numberSum.hpp"
#include <iostream>
#include <iomanip>

void enterArray()
{
    int userIn, numIn;
    std::cout << "How many numbers would you like to enter?: " << std::endl;
    std::cin >> userIn;
    int* arrayPtr = new int[userIn];
    std::cout << "Please enter your " << userIn << " numbers below:" << std::endl << std::endl;
    for (int i=0; i<userIn; i++)
    {
        std::cout << "    " << std::setw(i+2) << "  ";
        std::cin >> numIn;
        arrayPtr[i]=numIn;
    }
    std::cout << std::endl;
    sumNumbers(arrayPtr, userIn);
    delete [] arrayPtr;
}

void sumNumbers(int* arrayPtr, int arrayLength)
{
    if ((arrayLength-1)==0)
        std::cout << "You're summation from the numbers entered: " << arrayPtr[0] << std::endl;
    else
    {
        int runningTotal=arrayPtr[arrayLength-1]+arrayPtr[arrayLength-2];
        arrayPtr[arrayLength-2]=runningTotal;
        arrayLength--;
        sumNumbers(arrayPtr, arrayLength);
    }
}

/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/29/18
** Description: The numberSum.cpp file contains the methods and functions
*               required to summarize an array of user inputted
*               values.
*********************************************************************/
#include "numberSum.hpp"
#include <iostream>
#include <iomanip>

/********************************************************************* 
** Description: void enterArray()
*               Menu information and prompt to enter necessary
*               function information.
*********************************************************************/
void enterArray()
{
    int userIn, numIn;
    std::cout << "How many numbers would you like to enter?: " << std::endl;
    userIn=validateNumberInput();
    int* arrayPtr = new int[userIn];
    std::cout << std::endl << "Please enter your " << userIn << " numbers below:" << std::endl << std::endl;
    for (int i=0; i<userIn; i++)
    {
        std::cout << "    " << std::setw(i+2) << "  ";
        numIn=validateIntegerInput();
        arrayPtr[i]=numIn;
    }
    std::cout << std::endl;
    sumNumbers(arrayPtr, userIn);
    delete [] arrayPtr;
    startMenu();
}

/********************************************************************* 
** Description: void sumNumbers(int* arrayPtr, int arrayLength)
*               Recursive function that adds the values entered by
*               the user in the array.
*********************************************************************/
void sumNumbers(int* arrayPtr, int arrayLength)
{
    if ((arrayLength-1)==0)
        std::cout << "You're summation from the numbers entered: " << arrayPtr[0] << std::endl << std::endl;
    else
    {
        int runningTotal=arrayPtr[arrayLength-1]+arrayPtr[arrayLength-2];
        arrayPtr[arrayLength-2]=runningTotal;
        arrayLength--;
        sumNumbers(arrayPtr, arrayLength);
    }
}

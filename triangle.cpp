/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/29/18
** Description: The triangle.cpp file contains the methods and functions
*               required to find the triangular number of a given 
*               integer
*********************************************************************/
#include "triangle.hpp"
#include <iostream>
#include <string>

/********************************************************************* 
** Description: void enterTriangle()
*               Menu information and prompt to enter necessary
*               function information.
*********************************************************************/
void enterTriangle()
{
    int userIn, finalTriangle;
    std::cout << "Please enter a positive integer N: " << std::endl << std::endl;
    userIn=validateNumberInput();
    finalTriangle=recursiveTriangle(userIn);
    std::cout << "You're triangular number is   --->   " << finalTriangle << std::endl << std::endl;
    startMenu();
}

/********************************************************************* 
** Description: int recursiveTriangle(int triangleSize)
*               Recursive function that calculates the triangular 
*               value of a given number
*********************************************************************/
int recursiveTriangle(int triangleSize)
{
    if (triangleSize==1)
    {
        return 1; // Base condition
    }
    else
    {
        return (triangleSize+recursiveTriangle(triangleSize-1));
    }
}

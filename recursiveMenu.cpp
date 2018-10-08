/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/29/18
** Description: The recursiveMenu.cpp file contains the methods and
*               functions needed to prompt the user for game 
*               information and details.
*********************************************************************/
#include <iostream>
#include "recursiveMenu.hpp"

/********************************************************************* 
** Description: void startMenu()
*               Contains the prompts necessary to move to the different
*               recursive functions.
*********************************************************************/
void startMenu()
{
    int userSelection; 
    std::cout << "*********** Welcome to the recursive function junction! ***********" << std::endl << std::endl;
    std::cout << "      Please select from one of the options below:" << std::endl;
    std::cout << "          1. Recursively print a string in reverse" << std::endl;
    std::cout << "           2. Recursively calculate the sum of an array of integers" << std::endl;
    std::cout << "            3.  Recursively calculate the triangular number of an integer N" << std::endl;
    std::cout << "             4.  Exit the recursive function junction :(" <<std::endl << std::endl;
    userSelection=mainMenuValidate();
    switch (userSelection)
    {
        case 1:
        enterString();
        break;
        
        case 2:
        enterArray();
        break;
        
        case 3:
        enterTriangle();
        break;
        
        case 4:
        exitMenu();
        break;
    }
}

/********************************************************************* 
** Description: void exitMenu()
*               Exit display used when leaving the program
*********************************************************************/
void exitMenu()
{
    std::cout << std::endl << "************ Thank you for playing! See you again soon! ************" << std::endl << std::endl;
}
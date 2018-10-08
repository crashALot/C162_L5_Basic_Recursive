/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        07/29/18
** Description: The recursiveValidate.cpp file contains the methods 
*               and functions required to validate user input.
*********************************************************************/
#include "recursiveValidate.hpp"
#include <iostream>
#include <string>
#include <cmath>

/********************************************************************* 
** Description: int mainMenuValidate()
*               Acts as a barrier to incorrect user inputs. Prompts
*               the user for new input if entered value is not 1, 2, 3,
*               or 4
*********************************************************************/
int mainMenuValidate()
{
    int go=1, length=0;
    std::string userIn;
    do
    {
        // http://www.cplusplus.com/forum/beginner/2624/
        // How to identify the Enter key when pressed alone 
        std::getline(std::cin, userIn);
        length=userIn.length();
        if (userIn[0]==' ' || length>1 || (userIn[0]-'0')>4 || (userIn[0]-'0')<1)
        {
            std::cout << "Please re-enter your choice as an integer between 1 and 4:" << std::endl;
        }
        else
        {
            // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            go=0; // Signal variable exits while loop
            return((int)userIn[0]-'0'); // Converts char to int via ASCII code math
        }
    }
    while (go);
    return 0;
}

/********************************************************************* 
** Description: int validateNumberInput()
*               Acts as a barrier to incorrect user inputs. Prompts
*               the user for new input if entered value is not a 
*               positive integer
*********************************************************************/
int validateNumberInput()
{
 int runTotal=0, go=1, length;
    do
    {
        std::string userIn;
        std::getline(std::cin, userIn);
        length=userIn.length();
        for (int i=0; i<length; i++)
        {
            if (isdigit(userIn[i]) && !(ispunct(userIn[i])) && !(isspace(userIn[i])))
            {
                // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-cs
                runTotal+=pow(10,length-1-i)*(userIn[i]-'0'); // Converts char back to int
                if ((i+1)==length)
                    go=0;
                if (!runTotal)
                {
                    std::cout << "Please enter a positive integer value (without spaces, commas, or periods) greater than 0: " << std::endl;
                    runTotal=0;
                    go=1;
                }
            }
            else
            {
                std::cout << "Please enter a positive integer value (without spaces, commas, or periods) greater than 0: " << std::endl;
                runTotal=0;
                break;
            }   
        }
    } while (go);
    return runTotal;
}

/********************************************************************* 
** Description: int validateNumberInput()
*               Acts as a barrier to incorrect user inputs. Prompts
*               the user for new input if entered value is not an 
*               integer
*********************************************************************/
int validateIntegerInput()
{
 int runTotal=0, go=1, length;
 char tempChar;
 bool isNeg=false;
    do
    {
        std::string userIn;
        std::getline(std::cin, userIn);
        length=userIn.length();
        if (userIn[0]=='-')
        {
            isNeg=true;
            for (int i=1; i<length; i++)
            {
                tempChar=userIn[i];
                userIn[i]=userIn[i-1];
                userIn[i-1]=tempChar;
            }
            userIn.substr(0, length-1);
            length--;
        }

        for (int i=0; i<length; i++)
        {
            if (isdigit(userIn[i]) && !(ispunct(userIn[i])) && !(isspace(userIn[i])))
            {
                // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-cs
                runTotal+=pow(10,length-1-i)*(userIn[i]-'0'); // Converts char back to int
                if ((i+1)==length)
                    go=0;
                if (!runTotal)
                {
                    std::cout << "Please enter an integer value (without spaces, commas, or periods): " << std::endl;
                    runTotal=0;
                    go=1;
                }
            }
            else
            {
                std::cout << "Please enter an integer value (without spaces, commas, or periods): " << std::endl;
                runTotal=0;
                break;
            }   
        }
    } while (go);
    if (isNeg==true)
        return runTotal*-1;
    else
        return runTotal;
}

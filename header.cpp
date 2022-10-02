/**  
    CS700 ASSIGNMENT 1 SECTION 1
    DISHANT SHAH
    DUE DATE :- 2 OCT 2022
**/

#include<iostream>
#include <fstream>
#include <sstream>
#include <cstddef>
#include <string>
#include <regex>
#include <iomanip>
using namespace std;

int studentno;                                                              //Variable declaration
int examno;                                                                 //Variable declaration

/** 
   @brief return if the character is number or not 
   @param varaible of string type
   @return boolean value
**/
bool isNumber(string x)
{
    regex e ("\\d+");
    if (regex_match (x,e))
        return true;
    else
        return false;
}

/** 
   @brief returns average of the student
   @param variableOne dynamic 2D array of integer type
   @param variableTwo of integer type
   @param variableThree of integer type
   @param variableFour dynamic array of integer type
**/
void Average(int** a,int k,int j, int* c)
{
    for (int k = 0; k < examno; k++)
    {
        int sum = 0;
        for (int j = 0; j < studentno; j++)
        {
            sum += a[j][k];
        }
        c[k] = sum / studentno;
    }

}

/** 
   @brief return grade of the student
   @param variableOne dynamic 2D array of integer type
   @param variableTwo dynamic array of integer type
   @param variableThree of integer type
   @param variableFour of integer type
   @param variableFive dynamic array of character type
**/
void Getgrade(int** a, int* b, int k,int j, char** c)
{
    for (int k = 0; k < examno; k++)
    {
        for (int j = 0; j < studentno; j++)
        {
            if (b[k] - 5 < a[j][k] && a[j][k] < b[k] + 5)
                c[j][k] = 'C';
            else if (b[k] + 5 <= a[j][k] && a[j][k] < b[k] + 15)
                c[j][k] = 'B';
            else if (b[k] - 5 >= a[j][k] && a[j][k] > b[k] - 15)
                c[j][k] = 'D';
            else if (b[k] + 15 <= a[j][k])
                c[j][k] = 'A';
            else if (b[k] - 15 >= a[j][k])
                c[j][k] = 'F';

        }

    }
}

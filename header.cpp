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


bool isNumber(string x)
{
    regex e ("\\d+");
    if (regex_match (x,e))
        return true;
    else
        return false;
}

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

#include "linreg.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

double LinearRegresion::calculateMean()
{
    mean = 0;
    int s = 0;
    for(int i = 0; i < dependent_vars.size(); i++)
    {
        mean = mean + dependent_vars.at(i);
        s++;
    }
    mean = mean / s;
    return mean;
}

//double LinearRegresion::calculateSSE();

void LinearRegresion::getDataPaths(string path1, string path2)
{
    d_path = path1;
    i_path = path2;
}
void LinearRegresion::FillVectors()
{
    //Fill dependent_vars
    ifstream d_data(d_path);
    double d_num = 0.0;
    while(d_data >> d_num)
    {
        dependent_vars.push_back(d_num);
    }

    //Fill independent_vars
    ifstream i_data(i_path);
    double i_num = 0.0;
    while(i_data >> i_num)
    {
        independent_vars.push_back(i_num);
    }
}

void LinearRegresion::testStuff()
{   /*
    cout << "depend" << endl;
    for(int i = 0; i < dependent_vars.size(); i++)
        cout << dependent_vars.at(i) << " ";
    cout << endl;

    cout << "independ" << endl;
    for(int i = 0; i < independent_vars.size(); i++)
        cout << independent_vars.at(i)*2 << " ";
    cout << endl;
    */
    calculateMean();
    cout << "Mean value is:" << mean << endl;
}

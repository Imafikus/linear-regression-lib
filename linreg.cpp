#include "linreg.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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
{
    cout << "depend" << endl;
    for(int i = 0; i < dependent_vars.size(); i++)
        cout << dependent_vars.at(i)*3 << " ";
    cout << endl;

    cout << "independ" << endl;
    for(int i = 0; i < independent_vars.size(); i++)
        cout << independent_vars.at(i)*2 << " ";
    cout << endl;
}

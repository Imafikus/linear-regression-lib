#include "linreg.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void LinearRegresion::getObservationNum()
{
    observation_num = independent_vars.size();
}
double LinearRegresion::calculateDepMean()
{
    dep_mean = 0;
    int s = 0;
    for(int i = 0; i < observation_num; i++)
    {
        dep_mean = dep_mean + dependent_vars.at(i);
        s++;
    }
    dep_mean = dep_mean / s;
    return dep_mean;
}
double LinearRegresion::calculateIndMean()
{
    ind_mean = 0;
    int s = 0;
    for(int i = 0; i < observation_num; i++)
    {
        ind_mean = ind_mean + independent_vars.at(i);
        s++;
    }
    ind_mean = ind_mean / s;
    return ind_mean;
}

double LinearRegresion::calculateSSE()
{
    double s;
    for(int i = 0; i < observation_num; i++)
    {
        s = dependent_vars.at(i) -dep_mean;
        sse += s*s;
    }

    return sse;
}
void LinearRegresion::calculateB1()
{
    double e1 = 0; //current ind var - ind_mean
    double e2 = 0; //current dep var - dep_mean
    double e3 = 0; //e1 squared

    double s1 = 0;// final sum will be s1/s2
    double s2 = 0;

    for(int i = 0; i < observation_num; i++)
    {
        e1 = independent_vars.at(i) - ind_mean;
        e2 = dependent_vars.at(i) - dep_mean;
        s1 += e1 * e2;

        e3 = e1 * e1;
        s2 += e3;
    }
    b1 = s1/s2;
}
void LinearRegresion::calculateB0()
{
    b0 = dep_mean - b1 * ind_mean;
}
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

void LinearRegresion::printCentroid()
{
    cout << ind_mean << " " << dep_mean << endl;
}
void LinearRegresion::testStuff()
{
    //FillVectors();
    getObservationNum();
    calculateIndMean();
    calculateDepMean();
    calculateB1();
    calculateB0();
    cout << b1 << endl;
    cout << b0 << endl;


}

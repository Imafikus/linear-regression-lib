#ifndef LINREG_H
#define LINREG_H
#include <string>
#include <vector>

class LinearRegresion
{
private:

    std::vector<double> dependent_vars; //vector for dependent vars
    std::vector<double> independent_vars; //vector for independent vars

    int observation_num; //number of "dots" on our graph
    double dep_mean; //mean value for dependent vars
    double ind_mean; //mean value for independent vars
    double sse; //sum of square errors
    double b1; //slope in equation
    double b0; //intercept in equation

    //paths of data files
    std::string d_path;
    std::string i_path;

    void getObservationNum();
    double calculateDepMean();
    double calculateIndMean();
    double calculateSSE();
    void calculateB1();
    void calculateB0();

public:
    void FillVectors();
    void getDataPaths(std::string path1, std::string path2);// gets paths for dependent/independent data
    void printCentroid();
    void testStuff();

};



#endif // LINREG_H

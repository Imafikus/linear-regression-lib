#ifndef LINREG_H
#define LINREG_H
#include <string>
#include <vector>

class LinearRegresion
{
private:

    std::vector<double> dependent_vars; //vector for dependent vars
    std::vector<double> independent_vars; //vector for independent vars

    int observed_vars_number; //number of "dots" on our graph

    //paths of data files
    std::string d_path;
    std::string i_path;

public:
    void FillVectors();
    void getDataPaths(std::string path1, std::string path2);// gets paths for dependent/independent data
    void testStuff();

};



#endif // LINREG_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

class Datas{
    
    public:
    
    Datas(string);
    void getNextInputs(vector<double> &,string);
    void getNextExpectedValue(vector<double> &);
    
    private:
    ifstream _DatasFile;
    
};
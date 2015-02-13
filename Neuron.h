#pragma once
#include<vector>
#include<cstdlib>
#include"Network.h"
using namespace std;

class Neuron;

typedef vector<Neuron> Layer;

class Neuron
{
    public:
        Neuron();
        ~Neuron();
    void SetResults(double);
    void SetCoeff (vector<double>);
    double GetResults();
    void SetOutput(double);
    void SetDiffCoeff(double);
    void SetInput(double);
    void SetPartialDervatives(vector<double>);
    double GetDiffCoeff();
    double GetOutput();
    double GetInput();
    vector <double> GetPartialDerivatives();
    
    
    
    vector<double> GetCoeff();
    double ResultCompute(Layer);
    double Activation(double);
    double Second(double);
    
    private:
        double _result;
        double _input;
       
        double _diffCoeff;
	    vector <double> _partialDerivatives;
	     vector<double> _coeff;
    
    int _nbLayers;
    int _nbNeurons;
};

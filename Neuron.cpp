#include "Neuron.h"
#include "Network.h"
#include <iostream>
#include<cstdlib>
#include <cmath>



Neuron::Neuron(){ //A la creation de chaque neurone on initialise les vecteurs de poids et de derivees partielles

	for(int i=0;i<_nbNeurons;i++){
		_coeff.push_back(rand()/double(RAND_MAX));
		_partialDerivatives.push_back(0);
	}

}

Neuron::~Neuron(){
    
}

void Neuron::SetResults(double result){
    _result=result;
}

double Neuron::GetResults(){
    return _result;
}


double Neuron::Activation(double t){
    return tanh(t);
}

vector<double> Neuron:: GetCoeff(){
    return _coeff;
}

void Neuron::SetOutput(double x){
    _result=x;
}

void Neuron::SetDiffCoeff(double coeff){
    _diffCoeff=coeff;
}

double Neuron::GetDiffCoeff()
{
    return _diffCoeff;
}

double Neuron::GetOutput(){
    return _diffCoeff;
}

double Neuron :: Second(double t){
    return 1-tanh(t)*tanh(t);
}

void Neuron::SetInput(double x) {
    _input=x;
}

double Neuron::GetInput(){
    return _input;
}

void Neuron::SetPartialDervatives(vector<double> p) {
_partialDerivatives=p;
}

void Neuron::SetCoeff(vector<double> x){
	_coeff=x;
    
}

vector<double> Neuron::GetPartialDerivatives(){
    return _partialDerivatives;
}
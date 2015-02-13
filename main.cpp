#include"Network.h"
#include"Neuron.h"
#include<iostream>
#include<istream>
#include<vector>
#include <array>
#include<cmath>
#include<cstdlib>
#include"Datas.h"
using namespace std;

typedef vector<Neuron> Layer;


int main()
{
 /*   
    //.....MODELE REGRESSION NON LINEAIRE.......//
 
    

    //fichier 42 valeurs importées
    Network Regression(4, 13);
    vector<double> entries;
    vector<double> input;
    vector<double> output;
    double lambda;
      data.getNextInputs(entries,"W:\Bureau\LnReturns.txt");
    data.getNextExpectedValue(output);
double y=output[1];
    
    for (int i=1; i<40; i++) { // 
        
        input[i]=entries[i];
        
    }
  
    vector<vector<vector<double>>> w;
    
   w=Regression.Gradient(input,y, 40, Regression);
    
    //... Prédiction...
    
    vector<double> pinput;
    double p42;
    double f=0.0; // Pour que la fonction transition tourne, la valeur f n'a pas d'importance.
    
    for (int j=1; j<40; j++){
    
        pinput[j]=entries[j+1];
    
    }
    
    
  Regression.Transition(w,pinput,f,40);
    p42=Regression.GetResult();
    cout << "la valeur prédite est "<< p42<<endl;
} */
   


	//**********************************************************XOR**************************************************************************************
	//Datas file("\\paradis\eleves\SCHARBIT\Bureau\Datas.txt");

vector<double> inputs; //Soit on importe les données à partir d'un fichier soit on teste directement comme il suit
vector<double> expectedVal;

inputs.push_back(1.0);
 inputs.push_back(0.0);
 inputs.push_back(1.0);
 inputs.push_back(1.0);

 expectedVal.push_back(1.0);
 expectedVal.push_back(0.0);

double res;
Network Net(3,4); //On crée un réseau de trois couches de quatre neurones

//file.getNextInputs(input);
//file.getNextExpectedValue(expectedVal);

vector<vector<vector<double>>> w=Net.Gradient(inputs,expectedVal,4,Net);

cout<<"Resultat"<<endl;

vector<double> pinput;
pinput.push_back(0.0);
pinput.push_back(0.0);
pinput.push_back(0.0);
pinput.push_back(0.0);


Net.Transition(w,pinput,expectedVal,4);

cout<< Net.GetResult();


}

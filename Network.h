#pragma once
#include<vector>
#include<cstdlib>
#include<array>
using namespace std;

class Neuron;
typedef vector<Neuron> Layer;

class Network
{
    public:
        Network(int,int);
        ~Network();
        void Transition(vector<vector<vector<double>>>&, vector<double>&, vector<double>&,int n);
        void BackPropagation(vector<double>&,vector<double> &);
        int GetNbLayers();
        int GetNbNeurons ();
        void SetNbLayers(int);
        void SetNbNeurons(int);
        vector<vector<vector<double>>> Gradient (vector<double>& , vector<double>&, int, Network);
        double GetResult();
    

    private:
        int _nbLayers;
        int _nbNeurons;
        double _error;
        vector<Layer> _layers;

};


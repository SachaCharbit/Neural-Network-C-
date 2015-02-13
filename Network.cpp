#include"Network.h"
#include<vector>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include"Neuron.h"
using namespace std;


Network::Network(int nbLayers, int nbNeurons){
_nbLayers=nbLayers;
_nbNeurons=nbNeurons;
    cout<<"creation du reseau de neurones" <<endl;
   
	 
    for(int i=0; i<nbLayers-1;i++){
        _layers.push_back(Layer()); //On colle un objet de type Layer à la fin _layer
		cout<<endl;
    for(int j=0; j<nbNeurons; j++){ 
        _layers.back().push_back(Neuron()); //On colle un objet de type Neuron() à la fin de la dernière couche créée
        cout << "O" <<flush;
		}
    }
	cout<<endl;
_layers.push_back(Layer());
	_layers.back().push_back(Neuron());  //On a un seul neurone sur notre couche de sortie.
	  cout << "O" <<flush;
}

Network::~Network(){
    
}
//******************Faire fonction pour rentrer les dnnŽes dans la couche d'entrŽe*****************************


void Network::Transition(vector<vector<vector<double>>>& w, vector<double>& x, vector<double>& y,int n){  //n le nombre d'inputs, x le vecteur d'inputs, y le vecteur de valeurs attendues

    double a=0.0;  //a renpresente l'input d'un Neuron
	vector <double>u; 

	 
    for(int k=0;k<_nbLayers-2;k++) {
     for(int l=0; l<_nbNeurons;l++){
         _layers[k][l].SetCoeff(w[k][l]);	
     }
    }


    for(int l=0; l<n-1;l++){
        for(int i=0;i<_nbNeurons;i++){
            a=a+_layers[0][i].GetCoeff()[l]*x[i];
			
        }
        _layers[0][l].SetInput(a);
        a=_layers[0][l].Activation(a);		
        _layers[0][l].SetOutput(a);   
        a=0;
    }
	


    
    for(int k=1;k<_nbLayers-1;k++){ 
        for(int l=0; l<_nbNeurons;l++){
            for(int i=0;i<_nbNeurons;i++){
                a=a+_layers[k-1][i].GetCoeff()[l]*_layers[k-1][i].GetOutput();
            }
            _layers[k][l].SetInput(a);
            a=_layers[k][l].Activation(a);
            _layers[k][l].SetOutput(a);    //On calcule l'ouput du Neuron l de la couche k
            a=0;
        }
    }

	_layers[_nbLayers-1][0].GetCoeff(); 


    for(int i=0; i<_nbNeurons;i++){
        a=a+_layers[_nbLayers-3][i].GetCoeff()[i];  
    }
 
    a=_layers[_nbLayers-2][0].Activation(a);

    _layers[_nbLayers-2][0].SetOutput(a);

    double o=_layers[_nbLayers-2][0].GetResults(); //represente le vecteur des tous les outputs de tous les neurones de la couche 
double err=0; 
for(int i=0;i<y.size();i++){
	err=err+(y[i]-o)*(y[i]-o);
}
err=sqrt(err);
    _layers[_nbLayers-2][0].SetDiffCoeff(err);

}

void Network::BackPropagation(vector<double>& x, vector<double>& y){  // y represente la valeur attendue, x les inputs
    _error=0.0;
    double a=0;
    vector<double> v;
    
    
    for(int i=_nbLayers-3;i>=0;i--)
    {
        for(int k=0; k<_nbNeurons;k++)
        {
            for(int j=0; j<_nbNeurons;j++)
            {
                a=a+(_layers[i+1][j].GetDiffCoeff())*(_layers[i][j].GetCoeff()[k])*_layers[i+1][j].Second(_layers[i+1][j].GetInput()); 
            }
            _layers[i][k].SetDiffCoeff(a);
            
        }
    }
    for(int i=0; i<_nbLayers-3; i++){ 
   
        for(int k=0; k<_nbNeurons;k++)
    {
        for(int j=0;j<_nbNeurons;j++)
        {
            v[j]=_layers[i+1][j].GetDiffCoeff()*_layers[i+1][j].Second(_layers[i+1][j].GetInput())*_layers[i][k].GetOutput();
        }
        _layers[i+1][k].SetPartialDervatives(v);
    }
}

}


vector<vector<vector<double>>> Network:: Gradient(vector<double>& x, vector<double>& y, int n, Network N) // n = nombre d'entrées, on utilise la methode du gradient descendant
{
    double lambda=0.6;
    double error=1;
    vector<vector<vector<double>>> w; //On cree des matrices 3d. Une matrice par iteration. Une matrice reprsente l'ensemble des poids des neurones de chaque couche
    vector<double> e;
	cout<<endl;
	vector<double>s;
	vector<vector<double>> u;
	vector<vector<double>> v;
	double r;



for(int k=1; k<_nbLayers-1;k++){
	v.clear();
	for(int j=0;j<_nbNeurons;j++){
	s.clear();
		for(int i=0;i<_nbNeurons;i++){
			r=rand()/double(RAND_MAX); //On genere les poids aleatoirement lors de la premiere iteration puis ils seront optimises
			s.push_back(r);
		}
		v.push_back(s);
	}
		w.push_back(v);
}


for(int i=0;i<n;i++){
r=rand()/double(RAND_MAX);
			s.push_back(r);
}
u.push_back(s);	
w.push_back(u);
//Notre matrice 3d de poids est cree


cout <<endl;


    while(error>0.001) {
   
        N.Transition(w,x,y,n); 

        N.BackPropagation(x,y);
		
        error=_layers[_nbLayers-2][0].GetDiffCoeff();

        for (int i=0; i<_nbLayers-3; i++) 
        {
            
            for (int j=0;j<n; j++){
                for (int k=0;k<n; k++){
                    
                    w[i][j][k]=w[i][j][k]-_layers[i][j].GetPartialDerivatives()[k]+lambda;
                    
                }
                
            }
        }

    return w;
}
}



    



int Network::GetNbLayers(){
return _nbLayers;
}

int Network::GetNbNeurons(){
return _nbNeurons;
}

void Network::SetNbLayers(int n){
    _nbLayers=n;
}

void Network::SetNbNeurons(int n){
    _nbNeurons=n;
}

double Network::GetResult(){
    int n=_nbLayers;
    return _layers[n-2][0].GetOutput();
}


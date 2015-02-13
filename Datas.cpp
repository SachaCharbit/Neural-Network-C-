#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include "Datas.h"
#include <string>
using namespace std;


Datas::Datas(string name){ //name correspond au nom du fichier dont on veut extraire les donnees
    _DatasFile.open(name.c_str());
}


void Datas::getNextInputs(vector <double>& input,string name){
   
    if(_DatasFile.eof()){
    cout << "fin du fichier" << endl;
	abort();
	}

	string L;
	 while(getline(_DatasFile, L)){
	 while(getline(_DatasFile, L)){
	//input.clear(); //Supprime le contenu d'input afin de pouvoir utiliser plusieurs fois la fonctio stringstream
     //On récupère la ligne à extraire et on la place dans le string L
	cout<<L;
	stringstream pile(L);  //Convertit le string en pile de double
    string element;
  
    pile>> element;
    
   string S="I";
    if(element.compare(S)==0){  
   double temp;
   
 //  if(compare(element,S)==0){   //Dans notre fichier de donnees, toutes les entrees seront precedee de input:
		
        while(pile>> temp){
            input.push_back(temp);
        }
	}
    }
	 }

	 _DatasFile.close();
	
}


void Datas::getNextExpectedValue(vector<double> &expected){
    if(_DatasFile.eof()){
        abort();
    }
    double temp;
    string L;
    stringstream pile(L);
    string element;
    
    getline(_DatasFile, L);
    expected.clear();
    pile>>element;
    
    
    if(element.compare("ExpectedOutput:")==0){ //Dans notre fichier de donnees, toutes les sorties attendues seront precedees de Expected output:
        while(pile>> temp){
            expected.push_back(temp);
        }
    }
}
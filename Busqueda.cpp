#include <iostream>
#include <cstring>

using namespace std;
#include "Busqueda.h"



bool Busqueda::getActiva(){return activa;}

int Busqueda::getID(){return id;}

int Busqueda::getAniosExp(){return aniosExp;}

int Busqueda::getIDRecruiter(){return idRecruiter;}

float Busqueda::getOfertaSalarial(){return oferta_salarial;}

bool Busqueda::getRemoto(){return remoto;}

string Busqueda::getNivelIngles(){return nivel_ingles;}

void Busqueda::getStack(string *vec){

    for(int i=0; i<cant_stack; i++){
        vec[i]="-";
        vec[i]=Stack[i];
    }
}

string Busqueda::getSeniority(){return seniority;}


void Busqueda::Cargar(){

    cout<<"ID: ";
    cin>>id;

    cout<<endl<<"ID del Recruiter: ";
    cin>>idRecruiter;

    cout<<endl<<"Oferta salarial: $";
    cin>>oferta_salarial;

    cout<<endl<<"¿ Acepta trabajo Remoto ? S/N : ";
    char op;
    cin>>op;
    if(toupper(op)=='S'){
        remoto=true;
    }
    else{remoto=false;}

    cout<<endl;

    string aux;
    cin.ignore();
    cout<<"Nivel de Ingles: ";
    getline(cin,aux);
    strcpy(nivel_ingles,aux.c_str());

    cout<<endl;

    cout<<"Agregar stack? S/N : ";

    //Funcion para cargar vector de Stack
    cin>>op;
    int i=0;
    while(toupper(op)=='S' && i<cant_stack){

        cin.ignore();
        cout<<"Ingrese stack: ";
        getline(cin,Stack[i]);
        i++;
        if(i<cant_stack){
            cout<<endl<<"Seguir cargando stack? S/N : ";
            cin>>op;
        }
        else{op='N';}

    }
    cout<<endl;

    cout<<"Anios de Exp: ";
    cin>>aniosExp;

    cout<<endl<<"Seniority: ";
    cin.ignore();
    getline(cin,aux);
    strcpy(seniority,aux.c_str());

    activa=true;
    cout<<endl<<"========================================================"<<endl;

}

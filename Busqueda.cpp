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

    cout<<endl<<"";

}

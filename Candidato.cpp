#include <iostream>
#include <cstring>
using namespace std;
#include "Candidato.h"


void Candidato::setDNI(int d){dni=d;}

void Candidato::setNombre(string n){strcpy(nombre,n.c_str());}

void Candidato::setApellido(string a){strcpy(apellido,a.c_str());}

void Candidato::setMail(string m){strcpy(mail,m.c_str());}

void Candidato::setTelefono(int t){telefono=t;}

void Candidato::setEmpresasTrabajadas(EmpresaTrabajada *vec){

    for(int i=0; i<3; i++){
        vEmpresas[i]=vec[i];
    }
}

void Candidato::setSeniority(string s){
    strcpy(seniority,s.c_str());
}

void Candidato::setStack(string *vec){

    for(int i=0; i<10; i++){
        vStack[i]=vec[i];
    }
}

void Candidato::setUbicacion(Ubicacion ubi){ubicacion=ubi;}

void Candidato::setSalarioPretendido(float s){salarioPretendido=s;}



int Candidato::getDNI(){return dni;}

string Candidato::getNombre(){return nombre;}

string Candidato::getApellido(){return apellido;}

string Candidato::getMail(){return mail;}

int Candidato::getTelefono(){return telefono;}

EmpresaTrabajada *Candidato::getEmpresasTrabajadas(){return vEmpresas;}

string Candidato::getSeniority(){return seniority;}

string *Candidato::getStack(){return vStack;}

Ubicacion Candidato::getUbicacion(){return ubicacion;}

float Candidato::getSalarioPretendido(){return salarioPretendido;}

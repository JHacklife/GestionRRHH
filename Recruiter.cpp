#include <cstring>
#include "Recruiter.h"
using namespace std;

void Recruiter::setID(int n){
    ID=n;
}

void Recruiter::setPassword(string pass){

    strcpy(password,pass.c_str());
}

void Recruiter::setNombre(string n){
    strcpy(nombre,n.c_str());
}

void Recruiter::setApellido(string ap){
    strcpy(apellido,ap.c_str());
}

int Recruiter::getID(){ return ID;}

string Recruiter::getPassword(){return password;}

string Recruiter::getNombre(){return nombre;}

string Recruiter::getApellido(){return apellido;}



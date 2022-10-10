#include <iostream>
#include <cstring>
#include "Empresa.h"

using namespace std;

void Empresa::setCodigo(string c){
    strcpy(cod,c.c_str());
}

void Empresa::setCUIT(int c){
    CUIT=c;
}

void Empresa::setNombre(string n){
    strcpy(nombre,n.c_str());
}

void Empresa::setTelRRHH(int t){
    telRRHH=t;
}

void Empresa::setUbicacion(Ubicacion ubi){
    ubicacion=ubi;
}

string Empresa::getCodigo(){return cod;}

string Empresa::getNombre(){return nombre;}

int Empresa::getCUIT(){return CUIT;}

int Empresa::getTelRRHH(){return telRRHH;}

Ubicacion Empresa::getUbicacion(){ return ubicacion;}


void Empresa::Cargar(){

    string aux;
    cout<<"Codigo de empresa: ";
    cin>>aux;
    setCodigo(aux);
    cout<<endl;

    cout<<"Nombre : ";
    cin>>aux;
    setNombre(aux);
    cout<<endl;

    cout<<"CUIT: ";
    cin>>CUIT;
    cout<<endl;

    cout<<"Tel. de RRHH: ";
    cin>>telRRHH;
    cout<<endl;

    cout<<"Ubicacion: "<<endl;
    ubicacion.Cargar();
}

void Empresa::Mostrar(){

    cout<<cod<<endl;
    cout<<nombre<<endl;
    cout<<CUIT<<endl;
    cout<<telRRHH<<endl;
    ubicacion.Mostrar();
    cout<<"---------------------------------"<<endl;

}

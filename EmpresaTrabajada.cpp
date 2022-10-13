#include<iostream>
#include<cstring>
#include "EmpresaTrabajada.h"

using namespace std;

//Constructor
EmpresaTrabajada::EmpresaTrabajada(){
    setEstado(false);
}


void EmpresaTrabajada::setSeniority(string sen){

    strcpy(seniority,sen.c_str());
}

void EmpresaTrabajada::setFechaIngreso(Fecha ingreso){
    fechaIngreso=ingreso;
}

void EmpresaTrabajada::setFechaEgreso(Fecha egreso){
    fechaEgreso=egreso;
}

void EmpresaTrabajada::setEstado(bool est){
    estado=est;
}

string EmpresaTrabajada::getSeniority(){return seniority;}

Fecha EmpresaTrabajada::getFechasIngreso(){return fechaIngreso;}

Fecha EmpresaTrabajada::getFechaEgreso(){return fechaEgreso;}

bool EmpresaTrabajada::getEstado(){return estado;}

void EmpresaTrabajada::Cargar(){

    Empresa::Cargar();
    string aux;
    cout<<"Seniority: ";
    cin>>aux;
    cout<<endl;
    strcpy(seniority,aux.c_str());
    fechaIngreso.cargar();
    fechaEgreso.cargar();
    estado=true;
}

void EmpresaTrabajada::Mostrar(){

    Empresa::Mostrar();
    cout<<"Seniority: "<<seniority<<endl;
    cout<<"Fecha de ingreso: ";
    fechaIngreso.mostrar();
    cout<<endl<<"Fecha de Egreso: ";
    fechaEgreso.mostrar();
}

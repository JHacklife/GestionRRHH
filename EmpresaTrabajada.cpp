#include<iostream>
#include<cstring>
#include "EmpresaTrabajada.h"

using namespace std;


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

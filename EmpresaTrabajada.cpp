#include<iostream>
#include<cstring>
#include "EmpresaTrabajada.h"
using namespace std;

//Constructor
EmpresaTrabajada::EmpresaTrabajada() { setEstado(false); }
void EmpresaTrabajada::setSeniority(string sen) { strcpy(seniority, sen.c_str()); }
void EmpresaTrabajada::setFechaIngreso(Fecha ingreso) { fechaIngreso = ingreso; }
void EmpresaTrabajada::setFechaEgreso(Fecha egreso) { fechaEgreso = egreso; }
void EmpresaTrabajada::setEstado(bool est) { estado = est; }

string EmpresaTrabajada::getSeniority() { return seniority; }
Fecha EmpresaTrabajada::getFechasIngreso() { return fechaIngreso; }
Fecha EmpresaTrabajada::getFechaEgreso() { return fechaEgreso; }
bool EmpresaTrabajada::getEstado() { return estado; }

void EmpresaTrabajada::Cargar() {
    Empresa::Cargar();
    string aux;
    cout << "Seniority: ";
    cin >> aux;
    cout << endl;
    strcpy(seniority, aux.c_str());
    fechaIngreso.cargar();
    fechaEgreso.cargar();
    estado = true;
}

void EmpresaTrabajada::Mostrar() {
    Empresa::Mostrar();
    cout << "Seniority: " << seniority << endl;
    cout << "Fecha de ingreso: ";
    fechaIngreso.mostrar();
    cout << endl << "Fecha de Egreso: ";
    fechaEgreso.mostrar();
}

void Empresa ArchivoEmpresaTrabajada::leer(int pos) {
    Empresa empresaTrabajada;
    FILE* p;
    p = fopen("EmpresaTrabajada.dat", "rb");
    if (p == nullptr) { return empresaTrabajada; }

    fseek(p, sizeof(Empresa) * pos, SEEK_SET);
    fread(&empresaTrabajada, sizeof(Empresa), 1, p);
    fclose(p);
    return empresaTrabajada;
}

bool ArchivoEmpresaTrabajada::guardar(Empresa empresaTrabajada) {
    FILE* p;
    p = fopen("EmpresaTrabajada.dat", "ab");
    if (p == nullptr) { return false; }

    bool ok = fwrite(&empresaTrabajada, sizeof(Empresa), 1, p);
    fclose(p);
    return ok;
}


bool ArchivoEmpresaTrabajada::Modificar(Empresa empresaTrabajada, int pos) {
    FILE* p;
    p = fopen("EmpresaTrabajada.dat", "rb+");
    if (p == nullptr) { return false; }

    fseek(p, sizeof(Empresa) * pos, SEEK_SET);
    bool ok = fwrite(&empresaTrabajada, sizeof(Empresa), 1, p);
    fclose(p);
    return ok;
}

int ArchivoEmpresaTrabajada::getCantidad() {
    FILE* p;
    p = fopen("EmpresaTrabajada.dat", "rb");
    if (p == nullptr) { return 0; }

    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Empresa);
    fclose(p);
    return cant;
}
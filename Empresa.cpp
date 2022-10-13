#include <iostream>
#include <cstring>
#include "Empresa.h"
using namespace std;

void Empresa::setCodigo(string c) { strcpy(cod, c.c_str()); }
void Empresa::setCUIT(int c) { CUIT = c; }
void Empresa::setNombre(string n) { strcpy(nombre, n.c_str()); }
void Empresa::setTelRRHH(int t) { telRRHH = t; }
void Empresa::setUbicacion(Ubicacion ubi) { ubicacion = ubi; }

string Empresa::getCodigo() { return cod; }
string Empresa::getNombre() { return nombre; }
int Empresa::getCUIT() { return CUIT; }
int Empresa::getTelRRHH() { return telRRHH; }
Ubicacion Empresa::getUbicacion() { return ubicacion; }

void Empresa::Cargar() {
    string aux;
    cout << "Codigo de empresa: ";
    cin >> aux;
    setCodigo(aux);
    cout << endl;

    cout << "Nombre : ";
    cin >> aux;
    setNombre(aux);
    cout << endl;

    cout << "CUIT: ";
    cin >> CUIT;
    cout << endl;

    cout << "Tel. de RRHH: ";
    cin >> telRRHH;
    cout << endl;

    cout << "Ubicacion: " << endl;
    ubicacion.Cargar();
}

void Empresa::Mostrar() {
    cout << cod << endl;
    cout << nombre << endl;
    cout << CUIT << endl;
    cout << telRRHH << endl;
    ubicacion.Mostrar();
    cout << endl;
}

void Empresa ArchivoEmpresa::leer(int pos) {
    EmpresaTrabajada empresa;
    FILE* p;
    p = fopen("Empresa.dat", "rb");
    if (p == nullptr) { return empresa; }

    fseek(p, sizeof(EmpresaTrabajada) * pos, SEEK_SET);
    fread(&empresa, sizeof(EmpresaTrabajada), 1, p);
    fclose(p);
    return empresa;
}

bool ArchivoEmpresa::guardar(EmpresaTrabajada empresa) {
    FILE* p;
    p = fopen("Empresa.dat", "ab");
    if (p == nullptr) { return false; }

    bool ok = fwrite(&empresa, sizeof(EmpresaTrabajada), 1, p);
    fclose(p);
    return ok;
}


bool ArchivoEmpresa::Modificar(EmpresaTrabajada empresa, int pos) {
    FILE* p;
    p = fopen("Empresa.dat", "rb+");
    if (p == nullptr) { return false; }

    fseek(p, sizeof(EmpresaTrabajada) * pos, SEEK_SET);
    bool ok = fwrite(&empresa, sizeof(EmpresaTrabajada), 1, p);
    fclose(p);
    return ok;
}

int ArchivoEmpresa::getCantidad() {
    FILE* p;
    p = fopen("Empresa.dat", "rb");
    if (p == nullptr) { return 0; }

    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(EmpresaTrabajada);
    fclose(p);
    return cant;
}
#include <iostream>
using namespace std;
#include "Fecha.h"

Fecha::Fecha() {
    _dia = 1;
    _mes = 1;
    _anio = 1111;
}

void Fecha::setDia(int dia) { _dia = dia; }
void Fecha::setMes(int mes) { _mes = mes; }
void Fecha::setAnio(int anio) { _anio = anio; }

int Fecha::getDia() { return _dia; }
int Fecha::getMes() { return _mes; }
int Fecha::getAnio() { return _anio; }
void Fecha::mostrar() { cout << _dia << "/" << _mes << "/" << _anio << endl; }

void Fecha::cargar() {
    cout << "Dia: ";
    cin >> _dia;

    cout << endl << "Mes: ";
    cin >> _mes;

    cout << endl << "Anio: ";
    cin >> _anio;
}

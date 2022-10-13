#ifndef BUSQUEDA_H_INCLUDED
#define BUSQUEDA_H_INCLUDED

#include <iostream>
#include <cstring>
#include "funciones.h"
using namespace std;


const int cant_stack = 10;

class Busqueda {

private:
    int id;
    int idRecruiter;
    float oferta_salarial;
    bool remoto;
    char nivel_ingles[6];
    string Stack[cant_stack];
    int aniosExp;
    char seniority[4];
    bool activa;

public:
    void setActiva(bool act);

    int getID();
    int getIDRecruiter();
    float getOfertaSalarial();
    bool getRemoto();
    string getNivelIngles();
    void getStack(string *vec);
    int getAniosExp();
    string getSeniority();
    bool getActiva();
    void Cargar();
    void Mostrar();

};


#endif // BUSQUEDA_H_INCLUDED

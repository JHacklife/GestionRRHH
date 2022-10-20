#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "Recruiter.h"

const int ANCHO_VENTANA = 120;
const int ALTO_VENTANA = 30;

const int cant_stack = 10;
const int tam_stack = 15;


void cargarCadena(char *pal, int tam);
void DivisorHorizontal(int y, char figura);
void cartel(int posx,int posy, int ancho, int alto);
void Borrarcartel(int posx,int posy, int ancho, int alto);

//Menus

void MenuPpal();
void MenuLogin(int &IdBusquedaActiva);
void MenuSeleccion(Recruiter usuario,int &IdBusquedaActiva);
void MenuBusqueda(int _idRecruiter,int &IdBusquedaActiva);
void MostrarBusquedasDisponibles(int _id);
void MenuSelecPersonal(Recruiter usuario,int &IdBusquedaActiva);


void FiltroSalario();
#endif // FUNCIONES_H_INCLUDED

#include<iostream>
#include<cstring>
#include "rlutil.h"
#include "Menu.h"
using namespace std;

void Menu::setTitulo(int posx, int posy, char titulo[], int tamanio) {
    strcpy(this->titulo, titulo);
    rlutil::locate(posx, posy);
    cout << titulo;
    cout << endl;
}

//Constructor
Menu::Menu(int x, int y, int ancho, int alto, char titulo[], int cantidadOpciones, char opciones[][50]) {
    this->x = x;
    this->y = y;
    this->ancho = ancho;
    this->alto = alto;
    this->cantidadOpciones = cantidadOpciones;
    strcpy(this->titulo, titulo);
    for (int i = 0; i < cantidadOpciones; i++) {
        strcpy(this->opciones[i], opciones[i]);
    }
}


void Menu::cartel(int posx, int posy, int ancho, int alto) {
    for (int i = posx; i < posx + ancho; i++) {
        rlutil::locate(i, posy);
        cout << "-";
        rlutil::locate(i, posy + alto);
        cout << "-";
    }

    for (int i = posy; i < posy + alto; i++) {
        rlutil::locate(posx, i);
        cout << "|";
        rlutil::locate(posx + ancho, i);
        cout << "|";
    }

    rlutil::locate(posx, posy);
    cout << "+";
    rlutil::locate(posx + ancho, posy);
    cout << "+";
    rlutil::locate(posx, alto + posy);
    cout << "+";
    rlutil::locate(posx + ancho, alto + posy);
    cout << "+";
}
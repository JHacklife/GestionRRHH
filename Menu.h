#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

class Menu {
private:
    int x, y;
    int ancho, alto;
    int opcion;
    int cantidadOpciones;
    char titulo[50];
    char opciones[10][50];
public:
    Menu(int x, int y, int ancho, int alto, char titulo[], int cantidadOpciones, char opciones[][50]);
    void setTitulo(int posx, int posy, char titulo[], int tamanio);
    void cartel(int posx, int posy, int ancho, int alto);
};

#endif // MENU_H_INCLUDED
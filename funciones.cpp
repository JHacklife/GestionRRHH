
#include "funciones.h"
#include "rlutil.h"
using namespace std;



void cargarCadena(char *pal, int tam){

    int i;
    fflush(stdin);
    for(i=0; i<tam; i++){

        pal[i]=cin.get();
        if(pal[i]=='\n'){
            break;
        }
    }
    pal[i]='\0';
    fflush(stdin);
}


// Dibuja una linea horizontal en la cordenada y recibida, con la figura recibida. (ocupa todo el ancho de pantalla)
void DivisorHorizontal(int y, char figura){

    for(int i=1; i<=ANCHO_VENTANA; i++){

        rlutil::locate(i,y);
        cout<<figura;
    }
    cout<<endl;
}



void cartel(int posx,int posy, int ancho, int alto, int margen){

        posx -= margen;
        posy -= margen;
        ancho += (margen*2)-1;
        alto -=1;
        for(int i=posx; i<posx+ancho; i++){

            rlutil::locate(i,posy);
            cout<<"-";
            rlutil::locate(i,posy+alto);
            cout<<"-";
        }

        for(int i=posy; i<posy+alto; i++){

            rlutil::locate(posx,i);
            cout<<"|";
            rlutil::locate(posx+ancho,i);
            cout<<"|";
        }

        rlutil::locate(posx,posy);
        cout<<"+";
        rlutil::locate(posx+ancho,posy);
        cout<<"+";
        rlutil::locate(posx,alto+posy);
        cout<<"+";
        rlutil::locate(posx+ancho,alto+posy);
        cout<<"+";

}


void Borrarcartel(int posx,int posy, int ancho, int alto, int margen){

        posx -= margen;
        posy -= margen;
        ancho += (margen*2)-1;
        alto -=1;
        for(int i=posx; i<posx+ancho; i++){

            rlutil::locate(i,posy);
            cout<<" ";
            rlutil::locate(i,posy+alto);
            cout<<" ";
        }

        for(int i=posy; i<posy+alto; i++){

            rlutil::locate(posx,i);
            cout<<" ";
            rlutil::locate(posx+ancho,i);
            cout<<" ";
        }

        rlutil::locate(posx,posy);
        cout<<" ";
        rlutil::locate(posx+ancho,posy);
        cout<<" ";
        rlutil::locate(posx,alto+posy);
        cout<<" ";
        rlutil::locate(posx+ancho,alto+posy);
        cout<<" ";

}


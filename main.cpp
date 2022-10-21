#include <iostream>
#include <cstring>
using namespace std;
#include "funciones.h"
#include "rlutil.h"
#include "Menu.h"
#include "ArchivoBusquedas.h"
#include "ArchivoCandidatos.h"
#include "EmpresaTrabajada.h"
#include "ArchivoRecruiter.h"




int main()
{
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::cls();

    //MENU LOGIN
/*
    DivisorHorizontal(1,'=');
    DivisorHorizontal(2,'|');
    DivisorHorizontal(3,'=');

    cartel(48,5,20,4);
    rlutil::locate(50,7);
    cout<<"~RECRUIT CENTER~"<<endl;


    DivisorHorizontal(10,'=');
    DivisorHorizontal(11,'|');
    DivisorHorizontal(12,'=');

    rlutil::locate(55,18);
    cout<<"LOGIN"<<endl;

    cartel(53,16,8,4);


    rlutil::locate(55,24);
    cout<<"SALIR"<<endl;
    cartel(53,22,8,4);



    DivisorHorizontal(28,'_');

   int tecla=0;
   int y=18;
   int x=52;
   rlutil::hidecursor();
   rlutil::locate(52,18);
   cout<<">";
   while(tecla!=1){

        tecla=rlutil::getkey();

        switch(tecla){

        case 15: //DOWN
            rlutil::locate(x,y);
            cout<<" ";
            y+=24-18;
            if(y>24){
                y=24;
            }

            break;

        case 14: //UP
            rlutil::locate(x,y);
            cout<<" ";
            y-=24-18;
            if(y<18){
                y=18;
            }
            break;

        case 1: //ENTER

            break;

        default:

            break;
        }

        rlutil::locate(x,y);
        cout<<">";

   }

    //UP :   14
    //DOWN : 15
    //LEFT : 16
    //RIGHT: 17
    //ENTER 1

    system("pause");

*/

    //Menu PPAL
/*
    rlutil::cls();

    rlutil::setColor(rlutil::YELLOW);
    DivisorHorizontal(1,'=');
    DivisorHorizontal(2,'|');
    DivisorHorizontal(3,'=');

    cartel(44,10,32,12);


    rlutil::locate(46,12);
    cout<<"1 - BUSQUEDAS"<<endl;
    rlutil::locate(46,14);                   //Ver busquedas asignadas al recruiter y poder seleccionar una
    cout<<"2 - SELECCION DE CANDIDATOS"<<endl;
    rlutil::locate(46,16);    // Busca candidatos para la busqueda activa (Si no hay activa informa con cartel) // MENU CON OPCIONES DE FILTRADO, GUARDA CANDIDATOS SELECCIONADOS
    cout<<"3 - ENVIO DE SELECCION"<<endl;
    rlutil::locate(46,18);        // ENVIA AL CLIENTE DE BUSQUEDA LOS CANDIDATOS ELEGIDOS EN "SELECCION DE CANDIDATOS"
    cout<<"4 - DATOS DE CLIENTES"<<endl;
    rlutil::locate(46,20);                  // Muestra la informacion de Las empresas que son clientes.
    cout<<"0 - VOLVER A LOGIN"<<endl;

    DivisorHorizontal(26,'=');
    DivisorHorizontal(27,'|');
    DivisorHorizontal(28,'=');
    //rlutil::hidecursor();
    rlutil::anykey();

*/
    rlutil::cls();

    //CARGA BUSQUEDAS
    /*
    ArchivoBusquedas archivo;
    Busqueda busqueda;

    busqueda.Cargar();
    archivo.guardar(busqueda);
    system("cls");

    rlutil::anykey();
    */
    //Carga Recruiters
    /*
    ArchivoRecruiter archivo;
    Recruiter recruiter;

    recruiter.Cargar();
    archivo.guardar(recruiter);
    rlutil::cls();
    */
    //INICIO PROGRAMA


    MenuPpal();


    //system("pause");


}


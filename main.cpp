#include <iostream>
#include <cstring>
#include "funciones.h"
#include "rlutil.h"
using namespace std;




int main()
{

    string palabra;
    int largo = palabra.length();

    cartel(58,12,6,5,2);
    rlutil::locate(58,12);
    cout<<"LOGIN";

    rlutil::setColor(rlutil::BLUE);
    cartel(58,20,6,5,2);
    rlutil::locate(58,20);
    cout<<"SALIR";




    return 0;
}

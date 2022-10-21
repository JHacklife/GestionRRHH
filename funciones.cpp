#include<iostream>
#include "funciones.h"
#include "rlutil.h"

//Revisar estos includes

#include "ArchivoBusquedas.h"
#include "ArchivoCandidatos.h"
#include "ArchivoRecruiter.h"
#include "ArchivoFavoritos.h"
#include "ArchivoElegidos.h"
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



void cartel(int posx, int posy, int ancho, int alto) {

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


void Borrarcartel(int posx,int posy, int ancho, int alto){

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




// FILTROS ----------------------------------------------------------------------------------------------

void FiltroSalario(){

    system("cls");
    ArchivoFavoritos archFavoritos;


    float salario;
    cout<<"Ingrese salario maximo deseado: ";
    cin>>salario;
    cout<<endl;

    int tam=archFavoritos.getCantidad();

    Favoritos *vFavoritos = new Favoritos[tam];

    for(int i=0; i<tam; i++){
        vFavoritos[i]=archFavoritos.leer(i);
    }

    //Cuento las coincidencias para el filtro aplicado
    int coincidencias=0;

    for(int i=0; i<tam; i++){

        if(vFavoritos[i].getSalarioPretendido()<=salario){

            coincidencias++;
        }
    }

    if(coincidencias>0){
        //Vacio el archivo
        archFavoritos.vaciar();

        //Agrego las coincidencias al archivo vacio
        for(int i=0; i<tam; i++){

            if(vFavoritos[i].getSalarioPretendido()<=salario){

                archFavoritos.guardar(vFavoritos[i]);
            }
        }
        //Mostrar archivo antes de salir---> opcional
        cout<<"Coincidencias encontradas, ver "<<"'Favoritos'"<<endl;
    }
    else{

        //Si no hay coincidencias
        cout<<"No se hallaron coincidencias, no hay nuevos favoritos"<<endl;
    }
        system("pause");
    delete[] vFavoritos;

}





//MENUS

//BUSQUEDAS - MENU

void MostrarBusquedasDisponibles(int _id){

    ArchivoBusquedas archivo;
    Busqueda busqueda;

    int tam = archivo.getCantidad();

    for(int i=0; i<tam; i++){

        busqueda = archivo.leer(i);
        if(busqueda.getIDRecruiter()==_id){

            busqueda.Mostrar();
            cout<<endl;
        }
    }
}


void MenuBusqueda(Recruiter usuario,int &IdBusquedaActiva){

    bool on=true;
    char op;


    while(on){
        system("cls");

        cout<<"1 Busquedas disponibles"<<endl;
        cout<<"2 - Activar Busqueda / Mostrar B. Activa"<<endl;
        cout<<"0 - Atras"<<endl;

        cout<<"Elija una opcion: ";
        cin>>op;
        cout<<endl;

        switch(op){

        case '1':
            {
                system("cls");
                //Mostrar Busquedas que coincidan con el id del recruiter
                MostrarBusquedasDisponibles(usuario.getID());
                cout<<endl;
                system("pause");
            }
            break;

        case '2':
            {
                system("cls");
                if(IdBusquedaActiva!=-1){
                    //Mostrar B.activa
                    cout<<"Busqueda activa: "<<endl;
                    ArchivoBusquedas archivoB;
                    Busqueda busquedaActiva;
                    int x=archivoB.buscar(IdBusquedaActiva);
                    busquedaActiva=archivoB.leer(x);
                    busquedaActiva.Mostrar();
                    system("pause");

                }
                else{
                    int _id;
                    ArchivoBusquedas archivoB;
                    Busqueda busqueda;
                    cout<<"Ingrese ID de busqueda a Activar: ";
                    cin>>_id;
                    int pos=archivoB.buscar(_id);
                    if(pos!=-1){

                        busqueda=archivoB.leer(pos);
                        if(busqueda.getIDRecruiter()==usuario.getID()){
                            IdBusquedaActiva=busqueda.getID();
                            cout<<"Busqueda Activada correctamente"<<endl;
                        }
                        else{
                            system("cls");
                            cout<<"La Busqueda ingresada no coincide con el Recruiter logeado"<<endl;
                            system("pause");
                        }
                    }
                    else{
                        system("cls");
                        cout<<"La busqueda ingresada no existe! "<<endl;
                        system("pause");
                    }
                }
            }

            break;

        case '0':
            on=false;
            break;

        default:

            break;
        }
    }

}


//ExisteElegido

bool ExisteElegido(int _dni, int IdBusquedaActiva){

    ArchivoFavoritos archivoElegidos;
    int cant = archivoElegidos.getCantidad();
    Favoritos *vElegidos = new Favoritos[cant];
    archivoElegidos.leerTodos(vElegidos,cant);
    for(int i=0; i<cant; i++){
        if(vElegidos[i].getDNI()==_dni && vElegidos[i].getIdBusqueda()==IdBusquedaActiva){
            delete[] vElegidos;
            return true;
        }
    }
    delete[] vElegidos;
    return false;
}


//Menu Filtros

void MenuFiltros(Recruiter usuario,int& IdBusquedaActiva){

    ArchivoFavoritos archivoFav;
    int cant = archivoFav.getCantidad();
    if(cant<=0){
        ArchivoCandidatos archivocand;
        int cant2 = archivocand.getCantidad();
        Candidato *candidatos = new Candidato[cant2];
        Favoritos *favoritos = new Favoritos[cant2];
        archivocand.leerTodos(candidatos,cant2);
        //Matriz auxiliar para setear stack
        char stck[cant_stack][tam_stack];

        for(int i=0; i<cant2; i++){

            //Carga los candidatos en el archivo de favoritos
            favoritos[i].setIdBusqueda(IdBusquedaActiva);
            favoritos[i].setIdRecruiter(usuario.getID());
            favoritos[i].setDNI(candidatos[i].getDNI());
            favoritos[i].setNombre(candidatos[i].getNombre());
            favoritos[i].setApellido(candidatos[i].getApellido());
            favoritos[i].setMail(candidatos[i].getMail());
            favoritos[i].setTelefono(candidatos[i].getTelefono());
            favoritos[i].setEmpresasTrabajadas(candidatos[i].getEmpresasTrabajadas());
            favoritos[i].setSeniority(candidatos[i].getSeniority());
            candidatos[i].CopiarStack(stck);
            favoritos[i].setStack(stck);
            favoritos[i].setUbicacion(candidatos[i].getUbicacion());
            favoritos[i].setSalarioPretendido(candidatos[i].getSalarioPretendido());
            archivoFav.guardar(favoritos[i]);

        }


        delete[] candidatos;
        delete[] favoritos;
    }

    bool on = true;
        char op;
        while(on){
            system("cls");

            cout<<"1 - Filtrar por Salario pretendido"<<endl;
            cout<<"2 - Filtrar por..."<<endl;
            cout<<"3 - Filtrar por..."<<endl;
            cout<<"4 - Filtrar por..."<<endl;
            cout<<"5 - Filtrar por..."<<endl;
            cout<<"6 - Filtrar por..."<<endl;
            cout<<"7 - Filtrar por..."<<endl;
            cout<<"0 - Volver a Seleccion"<<endl;

            cout<<"Elegir opcion: "<<endl;
            cin>>op;

            switch(op){

            case '1':
                {
                    FiltroSalario();
                }
                break;

            case '2':

                break;

            case '3':

                break;


            case '0':
                {
                    on=false;
                }
                break;

            default:

                break;
            }
        }

}


//Menu Seleccion de Personal (filtros/canidatos/etc)

void MenuSelecPersonal(Recruiter usuario, int& IdBusquedaActiva){

    bool on=true;
    char op;
    ArchivoFavoritos archivoF;

    while(on==true && IdBusquedaActiva!=-1){

        system("cls");
        cout<<"1 - Lista de Candidatos"<<endl;
        cout<<"2 - Filtros"<<endl;
        cout<<"3 - Favoritos"<<endl;
        cout<<"4 - Envio de Candidatos"<<endl;
        cout<<"0 - Atras"<<endl;

        cout<<"Elija una opcion: ";
        cin>>op;

        switch(op){

        case '1':
            {   //Muestro Lista Total de Candidatos.
                system("cls");
                ArchivoCandidatos archivoC;

                int tam = archivoC.getCantidad();
                Candidato *candidatos = new Candidato[tam];

                archivoC.leerTodos(candidatos,tam);

                for(int i=0; i<tam; i++){

                    candidatos[i].Mostrar();
                    cout<<"======================================================="<<endl;
                }
                system("pause");
                delete[] candidatos;

            }

            break;

        case '2'://Menu de Filtros
            {
                system("cls");

                MenuFiltros(usuario,IdBusquedaActiva);

            }

            break;

        case '3':
            {
                system("cls");
                //Si el archivo Favoritos tiene registros, los muestro
                int cant=archivoF.getCantidad();
                if(cant>0){

                    Favoritos *favoritos = new Favoritos[cant];

                    archivoF.leerTodos(favoritos,cant);

                    for(int i=0; i<cant; i++){

                        favoritos[i].Mostrar();
                        cout<<"====================================================="<<endl;
                    }
                    system("pause");
                    delete[] favoritos;
                }
                //SI NO, ESTA VACIO, INFORMO:
                else{

                    cout<<"El archivo de Favoritos esta vacío"<<endl;
                    system("pause");
                }

            }


            break;

        case '4':
            {
                system("cls");

                //Archivo final de candidatos elegidos
                ArchivoElegidos archivoElegidos;
                Favoritos elegido;


                if(archivoF.getCantidad()>0){
                    char opcion;
                    cout<<"Agregar Candidato a la busqueda activa? S/N : ";
                    cin>>opcion;
                    while(toupper(opcion)=='S'){
                        system("cls");

                        cout<<endl<<"Ingresar DNI del candidato seleccionado: ";
                        int _dni;
                        cin>>_dni;
                        //Me aseguro de que el dni ingresado exista en los Favoritos
                        if(archivoF.buscar(_dni)<0){
                            cout<<"Candidato Inexistente. "<<endl;
                            system ("pause");
                        }
                        else{

                            //Compruebo si existe el candidato en el archivo final para esta busqueda (no debe repetirse un candidato para la misma busqueda)
                            if(ExisteElegido(_dni,IdBusquedaActiva)){
                                cout<<endl<<"El candidato ingresado ya ha sido enviado a la Busqueda Activa"<<endl;
                                system("pause");

                            }
                            else{
                                //Si existe y no esta repetido para la busqueda, lo guardo en el archivo Elegidos.Dat
                                int posicion=archivoF.buscar(_dni);
                                elegido = archivoF.leer(posicion);
                                elegido.setIdBusqueda(IdBusquedaActiva);
                                archivoElegidos.guardar(elegido);
                            }

                        }
                        system("cls");
                        cout<<endl<<"Desea Agregar otro candidato a la Busqueda ? S/N : ";
                        cin>>opcion;
                    }

                }
                else{
                    cout<<"No hay ningun favorito para cargar. "<<endl;
                    system("pause");
                }


            }
            break;

        case '0':
            {
                on=false;
            }
            break;

        default:

            break;
        }
    }

}


void MenuSeleccion(Recruiter usuario,int &IdBusquedaActiva){

    bool on=true;
    char op;

    while(on){

        system("cls");
        cout<<"1 - Busquedas"<<endl;
        cout<<"2 - Seleccion de Personal"<<endl;
        cout<<"0 - Atras"<<endl;

        cout<<"Elija una opcion: ";
        cin>>op;

        switch(op){

        case '1':
            system("cls");
            MenuBusqueda(usuario,IdBusquedaActiva);
            break;

        case '2':
            system("cls");

            cout<<"Seleccion de personal"<<endl;
            MenuSelecPersonal(usuario, IdBusquedaActiva);
            break;

        case '0':
            on=false;
            break;

        default:

            break;
        }
    }

}

void MenuLogin(int &IdBusquedaActiva){

    bool on=true;
    char op;
    int _id;
    string pass;
    ArchivoRecruiter archivo;

    while(on){
        bool logeado=false;
        system("cls");

        if(!logeado){
        cout<<"Ingrese ID: ";
        cin>>_id;
        cout<<endl<<"Ingrese password: ";
        cin>>pass;
        cout<<endl;
        logeado = archivo.loginExitoso(_id,pass);
        }
        //Si el login es exitoso mandar al menu de seleccion
        //Sino pregunta si desea reintentar, si dice que no, mandar al menu ppal

        if(logeado){
            Recruiter usuario;
            ArchivoRecruiter archivoUsuario;
            int pos=archivoUsuario.buscar(_id);
            usuario = archivoUsuario.leer(pos);
            system("cls");
            cout<<"Bienvenido, "<<usuario.getNombre()<<" :) "<<endl;
            system("pause");
            //Entra al menu de seleccion
            MenuSeleccion(usuario,IdBusquedaActiva);
            on=false;
        }
        else{
            cout<<"ID o password incorrectos, reintentar ? S/N: ";
            cin>>op;
            if(toupper(op)!='S'){
                on=false;
            }
        }
    }

}

void MenuPpal(){

    bool on=true;
    char op;

    while(on){
    int IdBusquedaActiva=-1;
    ArchivoFavoritos archivoF;
    archivoF.vaciar();
    system("cls");
    cout<<"1-LOGIN"<<endl;
    cout<<"0-SALIR"<<endl;
    cout<<"Elija una opcion: ";
    cin>>op;

    switch(op){

    case '1':
        {
            system("cls");
            MenuLogin(IdBusquedaActiva);
        }
        break;

    case '0':
        {
            system("cls");
            cout<<"Adios :)";
            on=false;
        }
        break;

    default:
        //SOLO SALE CON 0
        break;
    }

    }

}














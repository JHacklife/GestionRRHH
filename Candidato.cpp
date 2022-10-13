#include <iostream>
//#include <cstring>
#include <string>
using namespace std;
#include "Candidato.h"


void Candidato::setDNI(int d){dni=d;}

void Candidato::setNombre(string n){strcpy(nombre,n.c_str());}

void Candidato::setApellido(string a){strcpy(apellido,a.c_str());}

void Candidato::setMail(string m){strcpy(mail,m.c_str());}

void Candidato::setTelefono(int t){telefono=t;}

void Candidato::setEmpresasTrabajadas(EmpresaTrabajada *vec){

    for(int i=0; i<3; i++){
        vEmpresas[i]=vec[i];
    }
}

void Candidato::setSeniority(string s){
    strcpy(seniority,s.c_str());
}

void Candidato::setStack(string *vec){

    for(int i=0; i<10; i++){
        vStack[i]=vec[i];
    }
}

void Candidato::setUbicacion(Ubicacion ubi){ubicacion=ubi;}

void Candidato::setSalarioPretendido(float s){salarioPretendido=s;}



int Candidato::getDNI(){return dni;}

string Candidato::getNombre(){return nombre;}

string Candidato::getApellido(){return apellido;}

string Candidato::getMail(){return mail;}

int Candidato::getTelefono(){return telefono;}

EmpresaTrabajada *Candidato::getEmpresasTrabajadas(){return vEmpresas;}

string Candidato::getSeniority(){return seniority;}

void Candidato::getStack(string *vec){

    for(int i=0; i<10; i++){
        vec[i]="-";
        vec[i]=vStack[i];
    }
}

Ubicacion Candidato::getUbicacion(){return ubicacion;}

float Candidato::getSalarioPretendido(){return salarioPretendido;}


void Candidato::CargaDeStack(){

    //Vacio el vector para validar luego
    for(int i=0; i<10; i++){

        vStack[i]=" ";
    }

    char opcion;
    for(int i=0; i<10; i++){

        cout<<"Cargar stack S/N: ";
        cin>>opcion;
        if(toupper(opcion)=='S'){

            string aux;
            cout<<"Ingrese Lenguaje/Herramienta: ";
            cin.ignore();
            getline(cin,aux);
            vStack[i]=aux;
        }
        else{i=10;}
    }
}


void Candidato::Cargar(){

    cout<<"DNI: ";
    cin>>dni;

    cin.ignore();
    string aux;
    cout<<endl<<"Nombre: ";
    getline(cin,aux);
    strcpy(nombre,aux.c_str());

    cout<<endl<<"Apellido: ";
    getline(cin,aux);
    strcpy(apellido,aux.c_str());


    cout<<endl<<"Mail: ";
    getline(cin,aux);
    strcpy(mail,aux.c_str());


    cout<<endl<<"Telefono: ";
    cin>>telefono;

    //HACER FUNCION PRIVADA EN CLASE CANDIDATO PARA ESTO. EJ : void CargaExperiencia()
    char opcion;

    for(int i=0; i<3; i++){

        cout<<endl<<"Desea Cargar una Empresa? S/N : ";
        cin>>opcion;
        if(toupper(opcion)=='S'){
            cin.ignore();
            vEmpresas[i].EmpresaTrabajada::Cargar();
        }
        else{
            i=3;
        }
    }

    cin.ignore();
    cout<<endl<<"Seniority: ";
    getline(cin,aux);
    strcpy(seniority,aux.c_str());
    cout<<endl;

    CargaDeStack();

    cin.ignore();
    cout<<endl<<"Ubicacion: "<<endl;
    ubicacion.Cargar();


    cout<<"Salario pretendido: ";
    cin>>salarioPretendido;


}



void Candidato::Mostrar(){

    cout<<"Contacto: "<<endl;
    cout<<"----------"<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;
    cout<<"Mail: "<<mail<<endl;
    cout<<"Telefono: "<<telefono<<endl;

    ubicacion.Mostrar();
    cout<<endl;

    cout<<"Seniority: "<<seniority<<endl<<endl;
    cout<<"Stack:"<<endl;
    for(int i=0; i<10; i++){

        if(vStack[i]!=" "){
            cout<<vStack[i]<<endl;
        }
    }
    cout<<endl;

    cout<<"Experiencia: "<<endl<<endl;
    for(int i=0; i<3; i++){

        if(vEmpresas[i].getEstado()){
            vEmpresas[i].Mostrar();
            cout<<endl;
        }
    }

    cout<<"Salario Pretendido: "<<salarioPretendido<<endl;
    cout<<"---------------------------------------------------"<<endl;

}

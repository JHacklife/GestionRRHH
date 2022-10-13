#include <iostream>
#include <cstring>
using namespace std;
#include "Candidato.h"

void Candidato::setDNI(int d) { dni = d; }
void Candidato::setNombre(string n) { strcpy(nombre, n.c_str()); }
void Candidato::setApellido(string a) { strcpy(apellido, a.c_str()); }
void Candidato::setMail(string m) { strcpy(mail, m.c_str()); }
void Candidato::setTelefono(int t) { telefono = t; }
void Candidato::setEmpresasTrabajadas(EmpresaTrabajada* vec) {
    for (int i = 0; i < 3; i++) {
        vEmpresas[i] = vec[i];
    }
}
void Candidato::setSeniority(string s) { strcpy(seniority, s.c_str()); }
void Candidato::setStack(string* vec) {

    for (int i = 0; i < 10; i++) {
        vStack[i] = vec[i];
    }
}
void Candidato::setUbicacion(Ubicacion ubi) { ubicacion = ubi; }
void Candidato::setSalarioPretendido(float s) { salarioPretendido = s; }





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

        cout << " ";
    }

    char opcion;
    for(int i=0; i<10; i++){

        cout << "Cargar stack S/N: ";
        cin >> opcion;
        if (toupper(opcion) == 'S') {

            string aux;
            cout << "Ingrese Lenguaje/Herramienta: ";
            cin >> aux;
            vStack[i] = aux;
        }
        else{i=10;}
    }
}

void Candidato::Cargar() {
    cout << "DNI: ";
    cin >> dni;
    string aux;

    cout << endl << "Nombre: ";
    cin >> aux;
    strcpy(nombre, aux.c_str());

    cout << endl << "Apellido: ";
    cin >> aux;
    strcpy(apellido, aux.c_str());

    cout << endl << "Mail: ";
    cin >> aux;
    strcpy(mail, aux.c_str());

    cout << "Telefono: ";
    cin >> telefono;

    //HACER FUNCION PRIVADA EN CLASE CANDIDATO PARA ESTO. EJ : void CargaExperiencia()
    char opcion;

    for(int i = 0; i < cant_empresas; i++) {
        cout << endl << "Desea Cargar una Empresa? S/N : ";
        cin >> opcion;
        if (toupper(opcion) == 'S') {
            vEmpresas[i].EmpresaTrabajada::Cargar();
        }
        else {
            i = cant_empresas;
        }
    }

    cout << endl << "Seniority: ";
    cin >> aux;
    strcpy(seniority, aux.c_str());
    cout << endl;

    CargaDeStack();

    cout << endl << "Ubicacion: " << endl;
    ubicacion.Cargar();


    cout<<"Salario pretendido: "<<salarioPretendido<<endl;


}

void Candidato::Mostrar(){

    cout<<"DNI: "<<dni<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Mail: "<<mail<<endl;
    cout<<"Telefono: "<<telefono<<endl;
    cout<<"Experiencia: "<<endl;
    for(int i=0; i<cant_empresas; i++){

        if(vEmpresas[i].getEstado()){
            vEmpresas[i].EmpresaTrabajada::Mostrar();
            cout<<endl;
        }
    }

    cout<<"Seniority: "<<seniority<<endl;
    cout<<"Stack:"<<endl;
    for(int i=0; i<10; i++){

        if(vStack[i]!=" "){
            cout<<vStack[i]<<endl;
        }
    }

    ubicacion.Mostrar();

    cout<<endl<<"Salario Pretendido: "<<salarioPretendido<<endl;
    cout<<"---------------------------------------------------"<<endl;

}

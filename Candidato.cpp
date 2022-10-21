#include <iostream>
#include <cstring>

using namespace std;
#include "funciones.h"
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



void Candidato::setUbicacion(Ubicacion ubi){ubicacion=ubi;}

void Candidato::setSalarioPretendido(float s){salarioPretendido=s;}

void Candidato::setStack(char vec[][tam_stack]){

    for(int i=0; i<cant_stack; i++){

        for(int j=0; j<tam_stack; j++){

            Stack[i][j]=vec[i][j];
        }
    }

}


int Candidato::getDNI(){return dni;}

string Candidato::getNombre(){return nombre;}

string Candidato::getApellido(){return apellido;}

string Candidato::getMail(){return mail;}

int Candidato::getTelefono(){return telefono;}

EmpresaTrabajada *Candidato::getEmpresasTrabajadas(){return vEmpresas;}

string Candidato::getSeniority(){return seniority;}



Ubicacion Candidato::getUbicacion(){return ubicacion;}

float Candidato::getSalarioPretendido(){return salarioPretendido;}


void Candidato::CargaDeStack(){

    for(int i=0; i<cant_stack; i++){

        for(int j=0; j<tam_stack; j++){

            Stack[i][j]=' ';
        }
    }

    char op;
    cout<<"Cargar Stack? S/N : ";
    cin>>op;
    cout<<endl;

    int i=0;
    while(toupper(op)=='S' && i<cant_stack){

        cout<<"Ingrese stack: ";
        cargarCadenaStack(i);
        i++;

        if(i<cant_stack){
        cout<<"Cargar mas al stack ? S/N: ";
        cin>>op;
        }
        else{op='N';}

        cout<<endl;
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

    //Mostrar Stack
    cout<<"Stack: "<<endl;
    MostrarStack();

    cout<<"Experiencia: "<<endl;
    for(int i=0; i<3; i++){

        if(vEmpresas[i].getEstado()){
            vEmpresas[i].Mostrar();
            cout<<endl;
        }
    }
    cout<<endl;

    cout<<"Salario Pretendido: "<<salarioPretendido<<endl;
    cout<<"---------------------------------------------------"<<endl;

}


void Candidato::cargarCadenaStack(int pos){

    fflush(stdin);
    int j;
    for(j=0; j<tam_stack; j++){
        Stack[pos][j]=cin.get();
        if(Stack[pos][j]=='\n') break;
    }
    Stack[pos][j]='\0';
    fflush(stdin);

}

//ACTUALIZACION
void Candidato::CopiarStack(char stck[][tam_stack]){

    for(int i=0; i<cant_stack; i++){

        for(int j=0; j<tam_stack; j++){
            stck[i][j] = Stack[i][j];
        }
    }
}

bool Candidato::StackVacio(int pos){

      int caracteres=0;

      for(int i=0; i<tam_stack; i++){
            //Mientras no sea el fin de cadena ('\0') y no sea un espacio, sumo un caracter al contador
            if(Stack[pos][i]!='\0' && Stack[pos][i]!=' '){caracteres++;}
      }

      //Si tiene mas de 0, no esta vacia y devuelvo false, sino, está vacía y devuelvo true
      if(caracteres>0){return false;}
      return true;

    }

    void Candidato::getStackString(string Mstr[][tam_stack]){

    for(int i=0; i<cant_stack; i++){

        for(int j=0; j<tam_stack; j++){

            Mstr[i][j]+=Stack[i][j];
        }
    }

}


void Candidato::MostrarStack(){

    for(int i=0; i<cant_stack; i++){

        if(!StackVacio(i)){
            cout<<"\t";
            for(int j=0; j<tam_stack; j++){

                if(!StackVacio(i)){

                cout<<Stack[i][j];
                }

            }
            cout<<endl;
        }

    }
    cout<<endl;

}


#ifndef CANDIDATO_H_INCLUDED
#define CANDIDATO_H_INCLUDED

#include <cstring>
#include "funciones.h"
#include "EmpresaTrabajada.h"


class Candidato {

private:
    int dni;
    char nombre[15];
    char apellido[15];
    char mail[30];
    long int telefono;
    EmpresaTrabajada vEmpresas[3];
    char seniority[4];
    //Constantes tam y cant definidas en "funciones.h"
    char Stack[cant_stack][tam_stack];
    Ubicacion ubicacion;
    float salarioPretendido;

    void CargaDeStack();
    bool StackVacio(int pos);
    void cargarCadenaStack(int pos);
public:
    void setDNI(int d);
    void setNombre(string n);
    void setApellido(string a);
    void setMail(string m);
    void setTelefono(int t);
    void setEmpresasTrabajadas(EmpresaTrabajada *vec);
    void setSeniority(string s);

    void setUbicacion(Ubicacion ubi);
    void setSalarioPretendido(float s);

    int getDNI();
    string getNombre();
    string getApellido();
    string getMail();
    int getTelefono();
    EmpresaTrabajada *getEmpresasTrabajadas();
    string getSeniority();
    void getStackString(string Mstr[][tam_stack]);
    void MostrarStack();
    Ubicacion getUbicacion();
    float getSalarioPretendido();
    void Cargar();
    void Mostrar();

};




#endif // CANDIDATO_H_INCLUDED

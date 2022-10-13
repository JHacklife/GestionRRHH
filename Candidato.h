#ifndef CANDIDATO_H_INCLUDED
#define CANDIDATO_H_INCLUDED
#include <cstring>
#include "EmpresaTrabajada.h"

const int cant_empresas = 3;

class Candidato {
private:
    int dni;
    char nombre[15];
    char apellido[15];
    char mail[30];
    int telefono;
    EmpresaTrabajada vEmpresas[cant_empresas];
    char seniority[4];
    string vStack[10];
    Ubicacion ubicacion;
    float salarioPretendido;

    void CargaDeStack();
public:
    void setDNI(int d);
    void setNombre(string n);
    void setApellido(string a);
    void setMail(string m);
    void setTelefono(int t);
    void setEmpresasTrabajadas(EmpresaTrabajada* vec);
    void setSeniority(string s);
    void setStack(string* vec);
    void setUbicacion(Ubicacion ubi);
    void setSalarioPretendido(float s);

    int getDNI();
    string getNombre();
    string getApellido();
    string getMail();
    int getTelefono();
    EmpresaTrabajada* getEmpresasTrabajadas();
    string getSeniority();
    void getStack(string vec[]);
    Ubicacion getUbicacion();
    float getSalarioPretendido();
    void Cargar();
    void Mostrar();
};

#endif // CANDIDATO_H_INCLUDED
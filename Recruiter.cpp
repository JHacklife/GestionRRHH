#include <cstring>
#include "Recruiter.h"
using namespace std;

void Recruiter::setID(int n) { ID = n; }
void Recruiter::setPassword(string pass) { strcpy(password, pass.c_str()); }
void Recruiter::setNombre(string n) { strcpy(nombre, n.c_str()); }
void Recruiter::setApellido(string ap) { strcpy(apellido, ap.c_str()); }

int Recruiter::getID() { return ID; }
string Recruiter::getPassword() { return password; }
string Recruiter::getNombre() { return nombre; }
string Recruiter::getApellido() { return apellido; }

void Recruiter::Cargar() {
    /*
    int ID;
    char password[10];
    char nombre[20];
    char apellido[20];
    */
    string aux;
    cout << "ID: ";
    cin >> ID;

    cout << endl << "Password: ";
    cin >> aux;
    strcpy(password, aux.c_str());

    cout << endl << "Nombre: ";
    cin >> aux;
    strcpy(nombre, aux.c_str());

    cout << endl << "Apellido: ";
    cin >> aux;
    strcpy(apellido, aux.c_str());
    cout << endl;
}

void Recruiter::Mostrar() {
    cout << "ID: " << ID << endl;
    cout << "Password: " << password << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
}

void Recruiter ArchivoRecruiter::leer(int pos) {
    Recruiter recruiter;
    FILE* p;
    p = fopen("Recruiter.dat", "rb");
    if (p == nullptr) { return recruiter; }

    fseek(p, sizeof(Recruiter) * pos, SEEK_SET);
    fread(&recruiter, sizeof(Recruiter), 1, p);
    fclose(p);
    return recruiter;
}

bool ArchivoRecruiter::guardar(Recruiter recruiter) {
    FILE* p;
    p = fopen("Recruiter.dat", "ab");
    if (p == nullptr) { return false; }

    bool ok = fwrite(&recruiter, sizeof(Recruiter), 1, p);
    fclose(p);
    return ok;
}

bool ArchivoRecruiter::Modificar(Recruiter recruiter, int pos) {
    FILE* p;
    p = fopen("Recruiter.dat", "rb+");
    if (p == nullptr) { return false; }

    fseek(p, sizeof(Recruiter) * pos, SEEK_SET);
    bool ok = fwrite(&recruiter, sizeof(Recruiter), 1, p);
    fclose(p);
    return ok;
}

int ArchivoRecruiter::getCantidad() {
    FILE* p;
    p = fopen("Recruiter.dat", "rb");
    if (p == nullptr) { return 0; }

    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Recruiter);
    fclose(p);
    return cant;
}
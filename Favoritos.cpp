#include "Favoritos.h"
using namespace std;

//sets
void Favoritos::setIdBusqueda(int b){idBusqueda=b;}
void Favoritos::setElegido(bool e){elegido=e;}
//gets
int Favoritos::getIdBusqueda(){return idBusqueda;}
bool Favoritos::getElegido(){return elegido;}

void Favoritos::Mostrar(){

    Candidato::Mostrar();
}

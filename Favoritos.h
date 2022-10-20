#ifndef FAVORITOS_H_INCLUDED
#define FAVORITOS_H_INCLUDED

#include "Candidato.h"

class Favoritos : public Candidato {

private:
    int idBusqueda;
    bool elegido;
public:

    void setIdBusqueda(int b);
    void setElegido(bool e);
    bool getElegido();
    int getIdBusqueda();

    void Mostrar();

};

#endif // FAVORITOS_H_INCLUDED

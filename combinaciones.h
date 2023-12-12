#ifndef COMBINACIONES_H
#define COMBINACIONES_H
#include <iostream>

#include "combinacion.h"
class Combinaciones
{
private:
    Combinacion *inicio = NULL;
    Combinacion *fin = NULL;

public:
    Combinaciones(Combinacion *, Combinacion *);

    void nuevoCombinacion(Combinacion *);
    ~Combinaciones();
};

Combinaciones::Combinaciones(Combinacion *, Combinacion *)
{
    this->inicio = NULL;
    this->fin = NULL;
}
void Combinaciones::nuevoCombinacion(Combinacion *aux)
{
    if (inicio == NULL)
    {
        inicio = fin = aux;
    }
    else
    {
        fin->der = aux;
        aux->izq = fin;
        fin = aux;
    }
}

#endif
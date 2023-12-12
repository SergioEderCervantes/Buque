#ifndef COMBINACION_H
#define COMBINACION_H

#include <iostream>
#include "Mercancia.cpp"
class Combinacion
{
private:
    int volumen;
    int costo;
    Mercancia *mercancia;

public:
    Combinacion *izq = NULL;
    Combinacion *der = NULL;
    Combinacion(int, int, int);
};

Combinacion::Combinacion(int _volumen, int _costo, int _tam)
{
    this->volumen = _volumen;
    this->costo = _costo;
    this->mercancia = new Mercancia[_tam];
}

#endif
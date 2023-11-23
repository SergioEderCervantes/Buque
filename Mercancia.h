#ifndef MERCANCIA_H
#define MERCANCIA_H

#include <iostream>

using namespace std;

class Mercancia
{
private:
    string nombre;
    int volumen;
    int costo;
    int unidades;

public:
    Mercancia(string = "", int = 0, int = 0, int = 0);

    string getNombre();
    int getVolumen();
    int getCosto();
    int getUnidades();

    void setNombre(string);
    void setVolumen(int);
    void setCosto(int);
    void setUnidades(int);
};
#endif
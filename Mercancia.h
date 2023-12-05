#ifndef MERCANCIA_H
#define MERCANCIA_H

#include <iostream>

using namespace std;

class Mercancia
{
private:
    string nombre;
    int volumen;
    int costoUnidades;

public:
    Mercancia(string = "", int = 0, int = 0);

    string getNombre();
    int getVolumen();
    int getCostoUnidades();

    void setNombre(string);
    void setVolumen(int);
    void setCostoUnidades(int);

    friend void leerArchivo();
};
#endif
#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include <iostream>
#include <string>
using namespace std;

class Contenedor
{
    public:
        string nombre;
        int volumen;
        int costo;
        int unidades;
        Contenedor *izq=NULL;
        Contenedor *der=NULL;

        Contenedor(string = "", int = 0, int = 0, int = 0);

        string getNombre();
        int getVolumen();
        int getCosto();
        int getUnidades();

        void setNombre(string);
        void setVolumen(int);
        void setCosto(int);
        void setUnidades(int);

        void imprimirContenedor();

};

#endif
#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include <iostream>
#include <puerto.h>

using namespace std;

class Contenedor : public Puerto
{

    private:
        string nombre;
        int volumen;
        int costo;
        int unidades;

    public:
        Contenedor(string = "",int = 0, int = 0, int = 0);

        string getNombre();
        int getVolumen();
        int getCosto();
        int getUnidades();

        void setNombre(string);
        void setVolumen(int);
        void setCosto(int);
        void setUnidades(int);

        friend void leerArchivo();

         ~Contenedor();


};
#endif
#ifndef CONTENEDOR_H
#define CONTENEDOR_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include "puerto.h"
#define FILENAME "Buque.dat"

using namespace std;

class Contenedor : public Puerto
{

private:
    string nombre;
    int volumen;
    int costo;
    int unidades;

public:
    Contenedor(string = "", int = 0, int = 0, int = 0);

    string getNombre();
    int getVolumen();
    int getCosto();
    int getUnidades();

    void setNombre(string);
    void setVolumen(int);
    void setCosto(int);
    void setUnidades(int);

    void leerArchivo();
    void llenarArchivo(Contenedor *, int, int) const;

    // ~Contenedor();
};
#endif
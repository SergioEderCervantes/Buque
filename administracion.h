#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H

#include "puerto.h"
#include "contenedor.cpp"
#include <set>

class Administracion: public Puerto{

    private:
        int capacidad;
        int numProductos;
        
    public:

        Contenedor *inicio=NULL;
        Contenedor *fin=NULL;

        Administracion();

        void setCapacidad(int);
        int getCapacidad();

        void setNumProductos(int);
        int getNumProductos();

        virtual void area();
        bool validacionDatos();
        void resumenDatos();
        
        friend bool validarRango(const string &,int,int);
        friend bool validarLinea(string &, set<string>&);
        friend string procesarCadena(string cadena);

        void creacionContenedores();

        void ejecutarAdministracion();

    ~Administracion(){};
};

#endif
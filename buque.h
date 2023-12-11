#ifndef BUQUE_H
#define BUQUE_H

#include "puerto.h"
#include "contenedor.h"

class Buque : public Puerto{

    private: 
        int capacidad;
        int numProductos;
        Contenedor *contenedores;
    
    public:
        Buque(int=0,int=0);

        void setCapacidad(int);
        void setNumProductos(int);
        
        int getCapacidad();
        int getNumProductos();
        
        void crearContenedores();

        ~Buque();

};

#endif
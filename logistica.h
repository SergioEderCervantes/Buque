#ifndef LOGISTICA_H
#define LOGISTICA_H

#include "administracion.cpp"

class Logistica : public Administracion
{
    public:
        Logistica();
        virtual void area();

        // Va a englobar todos los demas metodos utilizados en esta clase
        void ejecutarLogistica();
        Contenedor *quickSort(Contenedor *vec, int n);
        void imprimirVectores(Contenedor*, int);
        Contenedor *generarCombinacionWin(Contenedor* vec, int n,int& valMax, int& elements, int capacidadBuque, int& volFinal);
        Contenedor *generarCombinacionWin(Contenedor *vec, int n, int& valMax, int &elements, int capacidadBuque, int& volFinal, int& combinacionesHechas);
        void mejorEmbarque();
        Contenedor *cuentaArticulos(Contenedor *vec, int &n);
        ~Logistica(){};

};

#endif
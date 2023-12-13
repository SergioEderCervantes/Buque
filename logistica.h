#ifndef LOGISTICA_H
#define LOGISTICA_H

#include "administracion.cpp"
#include<windows.h>

class Logistica : public Administracion
{
    public:
        Logistica();
        virtual void area();

        // Va a englobar todos los demas metodos utilizados en esta clase
        void ejecutarLogistica();
        Contenedor *quickSort(Contenedor *vec, int n);
        void imprimirVectores(Contenedor*, int);
        Contenedor *generarCombinacionWin(Contenedor* vec, int n,int& valMax, int& elements, int capacidadBuque, int& volFinal, long& combinacionesHechas);
        Contenedor *generarCombinacionWin(Contenedor *vec, int n, int& valMax, int &elements, int capacidadBuque, int& volFinal, long& combinacionesHechas, bool);
        void mejorEmbarque();
        Contenedor *cuentaArticulos(Contenedor *vec, int &n);
        void llenarArchRes(Contenedor*, int);
        inline void llenarArchRes(int);
        // friend string procesarCadena(Contenedor);
        ~Logistica(){};

};

#endif
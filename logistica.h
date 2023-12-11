#ifndef LOGISTICA_H
#define LOGISTICA_H

#include "administracion.h"

class Logistica : public Administracion
{
    private: 
        
    
    public:
        Logistica();
        virtual void area();

        // Va a englobar todos los demas metodos utilizados en esta clase
        void ejecutarLogistica();

        ~Logistica(){};
};

#endif
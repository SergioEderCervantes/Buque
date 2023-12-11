#ifndef BUQUE_H
#define BUQUE_H

#include "logistica.h"

class Buque : public Logistica{

    private: 
    
    public: 
        Buque();
        void area();
        
        //Aqui pondremos todos los metodos de buque;
        void ejecutarBuque();

        ~Buque(){};

};

#endif
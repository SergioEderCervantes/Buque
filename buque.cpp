#include "buque.h"

Buque::Buque(int capacidad, int numProductos){
    this->capacidad=capacidad;
    this->numProductos=numProductos;
}

void Buque::setCapacidad(int capacidad){
    this->capacidad=capacidad;

}

void Buque::setNumProductos(int numProductos){
    this->numProductos=numProductos;
}

int Buque::getCapacidad(){
    return this->capacidad;
}

int Buque::getNumProductos(){
    return this->numProductos;
}

void Buque::crearContenedores(){
    
    this->contenedores= new Contenedor[this->numProductos];

}
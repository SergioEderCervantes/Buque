#include "contenedor.h"
Contenedor::Contenedor(string _mercancia, int _volumen, int _costo, int _unidades) : nombre(_mercancia), volumen(_volumen), costo(_costo), unidades(_unidades) {}

// Getters
string Contenedor::getNombre() { return this->nombre; }
int Contenedor::getVolumen() { return this->volumen; }
int Contenedor::getCosto() { return this->costo; }
int Contenedor::getUnidades() { return this->unidades; }

// Setters

void Contenedor::setNombre(string _mercancia) { this->nombre = _mercancia; }
void Contenedor::setVolumen(int _volumen) { this->volumen = _volumen; }
void Contenedor::setCosto(int _costo) { this->costo = _costo; }
void Contenedor::setUnidades(int _unidades) { this->unidades = _unidades; }

void Contenedor::imprimirContenedor(){
    cout<<endl<<"\t\t\t\t\tMercancia: "<<this->nombre;
    cout<<endl<<"\t\t\t\t\tVolumen: "<<this->volumen;
    cout<<endl<<"\t\t\t\t\tCosto:"<<this->costo;
    cout<<endl<<"\t\t\t\t\tUnidades: "<<this->unidades;
    cout<<endl;
}

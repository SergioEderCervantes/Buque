#include "contenedor.h"

Contenedor::Contenedor(string _mercancia, int _volumen, int _costo, int _unidades) : nombre(_nombre), volumen(_volumen), costo(_costo), unidades(_unidades) {}

// Getters
string Contenedor::getMercancia() { return this->mercancia; }
int Contenedor::getVolumen() { return this->volumen; }
int Contenedor:getCosto() { return this->costo; }
int Contenedor::getUnidades() { return this->unidades; }

// Setters

void Contenedor::setMercancia(string _mercancia) { this->mercancia = _mercancia; }
void Contenedor::setVolumen(int _volumen) { this->volumen = _volumen; }
void Contenedor::setCosto(int _costo) { this->costo = _costo; }
void Contenedor::setUnidades(int _unidades) { this->unidades = _unidades; }

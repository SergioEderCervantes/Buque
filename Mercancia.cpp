#include "Mercancia.h"

Mercancia::Mercancia(string _nombre, int _volumen, int _costo, int _unidades) : nombre(_nombre), volumen(_volumen), costo(_costo), unidades(_unidades) {}

// Getters
string Mercancia::getNombre() { return this->nombre; }
int Mercancia::getVolumen() { return this->volumen; }
int Mercancia::getCosto() { return this->costo; }
int Mercancia::getUnidades() { return this->unidades; }

// Setters

void Mercancia::setNombre(string _nombre) { this->nombre = _nombre; }
void Mercancia::setVolumen(int _volumen) { this->volumen = _volumen; }
void Mercancia::setCosto(int _costo) { this->costo = _costo; }
void Mercancia::setUnidades(int _unidades) { this->unidades = _unidades; }

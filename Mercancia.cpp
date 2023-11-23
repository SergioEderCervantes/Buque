#include "Mercancia.h"

Mercancia::Mercancia(string nombre, int volumen, int coste, int unidades) : nombre(nombre), volumen(volumen), costo(costo), unidades(unidades) {}

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

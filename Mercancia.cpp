#include "Mercancia.h"

Mercancia::Mercancia(string _nombre, int _volumen, int _costoUnidades) : nombre(_nombre), volumen(_volumen), costoUnidades(_costoUnidades) {}

// Getters
string Mercancia::getNombre() { return this->nombre; }
int Mercancia::getVolumen() { return this->volumen; }
int Mercancia::getCostoUnidades() { return this->costoUnidades; }

// Setters

void Mercancia::setNombre(string _nombre) { this->nombre = _nombre; }
void Mercancia::setVolumen(int _volumen) { this->volumen = _volumen; }
void Mercancia::setCostoUnidades(int _costoUnidades) { this->costoUnidades = _costoUnidades; }

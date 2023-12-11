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


void Contenedor::leerArchivo()
{
    fstream file;
    Contenedor registro;
    int n, tam;
    file.open(FILENAME, ios::in);

    if (!file)
    {
        cerr << "No se puede abrir el archivo " << endl;
        return;
    }
    else
    {
        file >> n;
        file >> tam;
        cout << "Total de Mercancias: " << n << endl;
        cout << "Tamanio del buque: " << tam << endl;
        while (file >> registro.nombre >> registro.volumen >> registro.costo >> registro.unidades)
        {
            cout << registro.nombre << " " << registro.volumen << " " << registro.costo << " " << registro.unidades << endl;
        }
    }

    file.close();
}

void Contenedor :: llenarArchivo(Contenedor *registro, int n, int tam) const
{
    ofstream file;

    file.open(FILENAME, ios::binary);

    if (!file)
    {
        cerr << "No se puede abrir el archivo " << endl;
    }
    else
    {
        file << n << endl;
        file << tam << endl;
        for (int i = 0; i < n; i++)
        {
            file << registro[i].getNombre() << " " << registro[i].getVolumen() << " " << registro[i].getCosto() << " " << registro[i].getUnidades() << endl;
        }
        cout << "Archivo escrito correctamente" << endl;
    }
    fflush(stdin);
}



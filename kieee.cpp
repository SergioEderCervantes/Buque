#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "contenedor.cpp"
using namespace std;

// Definición de la estructura Elemento
struct Elemento {
    int tamano;
    string nombre;
};

// Función para generar combinaciones que quepan en el buque
vector<Contenedor> generarCombinacionesQueQuepan(Contenedor *elementos, int capacidadBuque, int n) {
    vector<Contenedor> prueba(elementos, elementos + sizeof(elementos) / sizeof(elementos[0]));

    for (int i = 0; i < (1 << n); ++i) {
        Contenedor *combinacionActual;
        int sumaActual = 0;

        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                if (sumaActual + elementos[j].getVolumen() <= capacidadBuque) {
                    combinacionActual ;
                    sumaActual += elementos[j].getVolumen();
                }
            }
        }

        if (sumaActual > 0) {
            prueba.push_back(*combinacionActual);
        }
    }

    return prueba;
}


int main() {
    int n = 10;
    Contenedor *vecDeContenedores = new Contenedor[n];
    int capacidadBuque = 1000;
    vector<Contenedor> combinacionesQueQuepan(vecDeContenedores, vecDeContenedores + sizeof(vecDeContenedores) / sizeof(vecDeContenedores[0]));

    combinacionesQueQuepan = generarCombinacionesQueQuepan(vecDeContenedores, capacidadBuque,n);

    // Imprimir combinaciones que quepan
    // imprimirCombinaciones(combinacionesQueQuepan);
    cout << endl << combinacionesQueQuepan.size();
    return 0;
}

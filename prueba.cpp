#include <iostream>
#include <cmath>
#include <typeinfo>
#include "logistica.cpp"
#include "administracion.cpp"
#include "buque.cpp"
using namespace std;

Contenedor **generarCombinacionesQueQuepan(const Contenedor *vec, int capacidadBuque, int n) {
    Contenedor **combinacionesQueQuepan;
    combinacionesQueQuepan = new Contenedor*[1<<n];

    for (int i = 0; i < (1 << n); ++i) {
        Contenedor *combinacionActual= new Contenedor[n];
        int sumaActual = 0;

        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                if (sumaActual + vec[j].volumen <= capacidadBuque) {
                    combinacionActual[j]=vec[j];
                    sumaActual += vec[j].volumen;
                }
            }
        }

        if (sumaActual > 0) {
            combinacionesQueQuepan[i]=combinacionActual;
        }
    }

    return combinacionesQueQuepan;
}

// Función para imprimir combinaciones
// void imprimirCombinaciones(const Contenedor **combinaciones) {
//     for (int i=0, ) {
//         cout << "{ ";
//         for (const auto& elemento : combinacion) {
//             cout << elemento.nombre << " ";
//         }
//         cout << "}" << endl;
//     }
// } 



int main() {
    // Datos de ejemplo
    Puerto *Titanic=new Buque();
    
    // Construir la lista doblemente ligada a partir de los datos
    Buque *embarque = static_cast<Buque*>(Titanic);
    embarque->validacionDatos();
    embarque->creacionContenedores();
    cout<<embarque->inicio->unidades<<endl;
    int n=0;
    Contenedor *q = embarque->inicio;
    cout<<embarque->getNumProductos();
    for (int i = 0; i <= 2; i++)
    {
        n+=embarque->inicio->unidades;
        
        if(i==(2)){

        }
        else
        {
           embarque->inicio=embarque->inicio->der;
        }
        cout<<n;
        
    }
    
    
    Contenedor *vec = new Contenedor[n];
    Contenedor *combinacion = new Contenedor[1<<n];
    
    while (q!=NULL)
    {
        for (int i = 0; i < q->unidades; i++)
        {
            Contenedor aux(q->getNombre(), q->getVolumen(), q->getCosto(), 1);
            vec[i]= aux;
            
        }
        q=q->der;
    }
    
    for (int i = 0; i < 1<<n; i++)
    {
        /* code */
    }
    
    
    
    // Generar todas las combinaciones a partir del inicio de la lista
    // generarCombinacionesQueQuepan(vec, );
    // Liberar la memoria de la lista

    return 0;
}

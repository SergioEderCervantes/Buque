#include <iostream>
#include <cmath>
#include <typeinfo>
#include "logistica.cpp"
#include "administracion.cpp"
#include "buque.cpp"
using namespace std;

Contenedor *quickSort(Contenedor *vec, int n);
Contenedor *acotarElementos(Contenedor*, int);
void imprimirVectores(Contenedor*, int);
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
    while (q!= NULL)
    {
        n+= q->unidades;
        q = q->der;
    }

    q = embarque->inicio;
    Contenedor *vec = new Contenedor[n];
    // Contenedor *combinacion = new Contenedor[1<<n];
    
    int suma = 0;
    //Crea un vector de contenedores de todas las  unidades 
    while (q!=NULL)
    {
        for (int i = suma; i < suma + q->unidades; i++)
        {
            Contenedor aux(q->getNombre(), q->getVolumen(), q->getCosto(), 1);
            vec[i]= aux;
        }
        suma+=q->unidades;
        q=q->der;
    }
    //Aqui es donde tengo que trabajar para acotar 
    //funcion la cual acota los elementos de la lista para generar las combinaciones si n es mayor a 10, creando un vector de los
    //10 mejores elementos estadisticamente hablando

    Contenedor *vecChido;
    if(n > 20)
    {
        vecChido = acotarElementos(vec,n);
        delete [] vec;
    }
    else
    {
        vecChido = vec;
    }
    imprimirVectores(vecChido,20);

    // Generar todas las combinaciones a partir del inicio de la lista
    // generarCombinacionesQueQuepan(vecChido,n);
    // Liberar la memoria de la lista

    return 0;
}
Contenedor *acotarElementos(Contenedor* vec, int n)
{
    Contenedor * pro = new Contenedor[20];
    cout << "HOLA";
    //Sacar todas las relaciones precio volumen de todo el vector
    for (int i = 0; i < n; i++)
    {

        vec[i].relacionPV = round(vec[i].getVolumen() / vec[i].getCosto());
    }
    cout << "HOLA";
    // relacionPV = quickSort(relacionPV,n);
    vec = quickSort(vec,n);
    for (int i = 0; i < 20; i++)
    {
        pro[i] = vec[i];
    }
    return pro;
}

Contenedor *quickSort(Contenedor *vec, int n)
{
    int i = 0, j = n - 1;
    Contenedor tmp;
    double pivot = vec[(i + j) / 2].relacionPV;
    while (i <= j)
    {
        while (vec[i].relacionPV < pivot)
            i++;
        while (vec[j].relacionPV > pivot)
            j--;
        if (i <= j)
        {
            tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
            i++;
            j--;
        }
    }
    if (0 < j)
        quickSort(vec, j + 1);
    if (i < n - 1)
        quickSort(&vec[i], n - i);
    return vec;
}

void imprimirVectores(Contenedor* vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl << vec[i].getNombre();
    }
    
}

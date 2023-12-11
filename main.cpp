#include "Funciones.h"

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n, tam;
    Contenedor *m;

    cout << "Ingrese el numero de mercancias: ";
    cin >> n;
    cout << "Ingrese el tamano del buque: ";
    cin >> tam;

    m = new Contenedor[n];
    // llenarContenedor(m, n);
    llenarContenedor(m,n,1);
    m->llenarArchivo(m, n, tam);
    m->leerArchivo();

    delete[] m;
    return 0;
}

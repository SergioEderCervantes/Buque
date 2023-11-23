#include "Funciones.h"

int main(int argc, char const *argv[])
{
    int n, tam;
    Mercancia *m;

    cout << "Ingrese el numero de mercancias: ";
    cin >> n;
    cout << "Ingrese el tamano del buque: ";
    cin >> tam;

    m = new Mercancia[n];
    llenarMercancia(m, n);

    llenarArchivo(m, n, tam);
    leerArchivo();

    delete[] m;
    return 0;
}

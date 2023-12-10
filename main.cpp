#include "Funciones.h"

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n, tam;
    Mercancia *m;

    cout << "Ingrese el numero de mercancias: ";
    cin >> n;
    cout << "Ingrese el tamano del buque: ";
    cin >> tam;

    m = new Mercancia[n];
    // llenarMercancia(m, n);
    llenarMercancia(m,n,1);
    llenarArchivo(m, n, tam);
    leerArchivo();

    delete[] m;
    return 0;
}

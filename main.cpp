#include "Funciones.h"

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n, tam;
    Contenedor *m;

    do
    {
        cout << "Ingrese el numero de mercancias: ";
        cin >> n;
    } while (n < 1 || n > 99);

    do
    {
        cout << "Ingrese el tamano del buque: ";
        cin >> tam;
    } while (tam < 1 || tam > 9999);

    m = new Contenedor[n];
    // llenarContenedor(m, n);
    llenarContenedor(m,n,1);
    m->llenarArchivo(m, n, tam);
    m->leerArchivo();

    delete[] m;
    return 0;
}

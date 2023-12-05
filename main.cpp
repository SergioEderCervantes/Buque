#include "Funciones.h"

int main(int argc, char const *argv[])
{
    int n, tam;
    Mercancia *m;

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

    m = new Mercancia[n];
    llenarMercancia(m, n);

    llenarArchivo(m, n, tam);
    leerArchivo();

    delete[] m;
    return 0;
}

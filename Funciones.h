#include "Mercancia.cpp"
#include <fstream>
#define FILENAME "Buque.dat"

void llenarMercancia(Mercancia *, int);
string procesarCadena(string);

// Archivos
void llenarArchivo(Mercancia *m, int n, int tam);
void leerArchivo();

void llenarMercancia(Mercancia *m, int n)
{
    string nombre;
    int volumen = 0, costoUnidades = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el nombre de la mercancia: ";
        cin >> nombre;
        cout << "Ingrese el volumen de la mercancia: ";
        cin >> volumen;
        cout << "Ingrese el costo de la mercancia: ";
        cin >> costoUnidades;
        m[i] = Mercancia(procesarCadena(nombre), volumen, costoUnidades);
    }
}

string procesarCadena(string cadena)
{
    string cadenaProcesada = "";
    for (int i = 0; i < cadena.length(); i++)
    {

        if (cadena[i] != ' ' && isalpha(cadena[i]))
        {
            cadenaProcesada += tolower(cadena[i]);
        }
    }
    return cadenaProcesada;
}

void llenarArchivo(Mercancia *registro, int n, int tam)
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
            file << registro[i].getNombre() << " " << registro[i].getVolumen() << " " << registro[i].getCostoUnidades() << endl;
        }
        cout << "Archivo escrito correctamente" << endl;
    }
    fflush(stdin);
}

void leerArchivo()
{
    fstream file;
    Mercancia registro;
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
        while (file >> registro.nombre >> registro.volumen >> registro.costoUnidades)
        {
            cout << registro.nombre << " " << registro.volumen << " " << registro.costoUnidades << endl;
        }
    }

    file.close();
}

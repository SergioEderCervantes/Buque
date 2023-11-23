#include "Mercancia.cpp"
#include <fstream>
#define FILENAME "Buque.dat"

void llenarMercancia(Mercancia *m, int n);

// Archivos
void llenarArchivo(Mercancia *m, int n, int tam);
void leerArchivo();

void llenarMercancia(Mercancia *m, int n)
{
    string nombre;
    int volumen, costo, unidades;
    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el nombre de la mercancia: ";
        cin >> nombre;
        cout << "Ingrese el volumen de la mercancia: ";
        cin >> volumen;
        cout << "Ingrese el costo de la mercancia: ";
        cin >> costo;
        cout << "Ingrese las unidades de la mercancia: ";
        cin >> unidades;
        m[i] = Mercancia(nombre, volumen, costo, unidades);
    }
}

void llenarArchivo(Mercancia *registro, int n, int tam)
{
    ofstream archivo;

    archivo.open("clientes.dat", ios::binary);

    if (!archivo)
    {
        cerr << "No se puede abrir el archivo " << endl;
    }
    for (int i = 0; i < n; i++)
    {
        archivo << n << endl;
        archivo << tam << endl;
        archivo.write((char *)(&registro[i]), sizeof(Mercancia));
    }

    fflush(stdin);
}

void leerArchivo()
{
    ifstream file;
    Mercancia registro;

    file.open(FILENAME, ios::binary | ios::in);

    if (!file)
    {
        cerr << "No se puede abrir el archivo " << endl;
        return;
    }
    else
    {
        while (file.read((char *)(&registro), sizeof(Mercancia)))
        {
            cout << endl;
            cout << " Nombre: " << registro.getNombre();
            cout << " Volumen: " << registro.getVolumen();
            cout << " Costo: " << registro.getCosto();
            cout << " Unidades: " << registro.getUnidades();
        }
    }

    file.close();
}

#include "contenedor.cpp"



string procesarCadena(string);

// Archivos
void llenarContenedor(Contenedor *, int);
void llenarContenedor(Contenedor *, int, int);

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

void llenarContenedor(Contenedor *m, int n)
{
    string nombre;
    int volumen = 0, costo = 0, unidades = 0;
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
        m[i] = Contenedor(procesarCadena(nombre), volumen, costo, unidades);
    }
}

void llenarContenedor(Contenedor *m, int n, int)
{
    ifstream ifile("BaseProductos.txt");
    ifile.clear();
    ifile.seekg(0);
    string line,id;
    int *repetidos = new int[n];
    //llenar el vector de -1 para mayor optimizacion
    for (int i = 0; i < n ; i++)
        repetidos[i] = -1;

    int random, precio, volumen, j =0;
    bool band;
    for (int i = 0; i < n; i++)
    {
        random = rand()%100;
        j = 0;
        band = false;
        //verificar que no exista el valor ya en *m
        while (!band && repetidos[j] != random)
        {
            if (repetidos[j] == -1)
                band = true;
            j++;
        }
        if (band)
        {
            repetidos[j-1] = random;

            //Buscar el valor random en la baseProductos
            ifile.clear();
            ifile.seekg(0);
            while (getline(ifile,line))
            {
                id = line.substr(0,2);
                if (stoi(id) == random)
                {
                    line.erase(0,4);
                    m[i].setNombre(line);
                    m[i].setCosto((1+rand()%(100))*100);
                    m[i].setVolumen((1+rand()%(5))*3);
                    m[i].setUnidades((1+rand()%(10))*5);
                }
            }            
        }
        else i--;
        
    }
    ifile.close();
}


#include "administracion.h"
#include <fstream>
#include <sstream>

Administracion::Administracion(){};

void Administracion::setCapacidad(int capacidad)
{
    this->capacidad = capacidad;
}

void Administracion::setNumProductos(int numProductos)
{
    this->numProductos = numProductos;
}

int Administracion::getCapacidad()
{
    return this->capacidad;
}

int Administracion::getNumProductos()
{
    return this->numProductos;
}

void Administracion::area()
{
    cout << endl << endl << "Entrando al area de administracion..." << endl;
}

bool validarRango(const string &numeroStr, int rangoMinimo, int rangoMaximo)
{
    try
    {
        int numero = stoi(numeroStr);

        // Verificar si el número está dentro del rango
        return (numero >= rangoMinimo && numero <= rangoMaximo);
    }
    catch (invalid_argument &)
    {
        // La conversión a entero falló (porque no es un número)
        return false;
    }
    catch (std::out_of_range &)
    {
        // El número está fuera del rango de representación de int
        return false;
    }
}

bool validarLinea(const string &linea, set<string> &mercanciasEncontradas)
{
    istringstream stream(linea);
    string mercancia, componente1, componente2, componente3;

    // Leer las partes de la línea
    if (stream >> ws >> mercancia >> ws >> componente1 >> ws >> componente2 >> ws >> componente3)
    {
        // Verificar si el nombre de la mercancía ya ha sido encontrado antes
        if (mercanciasEncontradas.count(mercancia) > 0)
        {
            return false; // Nombre repetido
        }

        // Agregar el nombre de la mercancía al conjunto
        mercanciasEncontradas.insert(mercancia);

        // Verificar longitud de mercancía y componentes
        if (mercancia.length() > 20 || componente1.length() > 5 || componente2.length() > 5 || componente3.length() > 5)
        {
            return false;
        }

        // Verificar que mercancía contiene solo letras minúsculas
        for (char c : mercancia)
        {
            if (!islower(c))
            {
                return false;
            }
        }

        // Verificar que los componentes son números
        try
        {
            int comp1 = stoi(componente1);
            int comp2 = stoi(componente2);
            int comp3 = stoi(componente3);

            // Verificar que los números están en el rango permitido
            if (comp1 < 1 || comp1 > 99999 || comp2 < 1 || comp2 > 99999 || comp3 < 1 || comp3 > 99999)
            {
                return false;
            }
        }
        catch (invalid_argument &)
        {
            // Si la conversión a entero falla, retorna false
            return false;
        }
        catch (out_of_range &)
        {
            // Si el número está fuera del rango de representación de int, retorna false
            return false;
        }
    }
    else
    {
        return false;
    }

    return true;
}

bool Administracion::validacionDatos()
{

    ifstream ifile("Buque.dat");
    if (!ifile)
    {
        cout << endl
             << "No pude abrir el archivo....";
        return false;
    }
    ifile.clear();
    ifile.seekg(0);

    string capacidad;
    string numProductos;

    string linea;
    int cont = 3;
    set<string> mercanciasEncontradas;
    bool error = false;

    getline(ifile, numProductos);

    if (validarRango(numProductos, 1, 99))
    {
        this->numProductos = stoi(numProductos);
    }
    else
    {
        cout << endl
             << "Tu parametro ingresado como numero de productos es incorrecto!";
        cout << endl
             << "Necesaria una correccion inmediata de la documentacion para poder realizar el proceso!";

        return false;
    }

    getline(ifile, capacidad);

    if (validarRango(capacidad, 1, 9999))
    {
        this->capacidad = stoi(capacidad);
    }
    else
    {
        cout << endl
             << "Tu parametro ingresado como capacidad del buque es incorrecto!";
        cout << endl
             << "Necesaria una corrección inmediata de la documentacion para poder realizar el proceso!";
        return false;
    }

    while (getline(ifile, linea))
    {
        if (!validarLinea(linea, mercanciasEncontradas))
        {
            cout << endl
                 << "Error en la linea #" << cont << " del archivo!" << endl;
            error = true;
        }

        cont++;
    }

    if (error)
    {
        cout << endl
             << "Necesaria una correccion inmediata de la documentacion para poder realizar el proceso!" << endl;
        return false;
    }

    ifile.close();

    return true;
}

void Administracion::creacionContenedores()
{

    ifstream ifile("Buque.Dat");

    if (!ifile)
    {
        cout << endl
             << "No pude abrir el archivo....";
        exit(1);
    }

    ifile.clear();
    ifile.seekg(0);

    string linea;
    string mercancia;
    int volumen, costo, unidades;

    getline(ifile, linea);
    getline(ifile, linea);

    while (ifile >> mercancia >> volumen >> costo >> unidades)
    {
        Contenedor *aux;
        aux = new Contenedor(mercancia, volumen, costo, unidades);

        if (this->inicio == NULL)
        {
            inicio = aux;
            aux->der = NULL;
            aux->izq = NULL;
        }
        else
        {

            this->fin->der = aux;
            aux->izq = this->fin;
        }

        fin = aux;

    }

    ifile.close();
}

void Administracion::resumenDatos()
{
    cout << endl
         << endl
         << endl
         << "\t\t\t\tSOLICITUD DE EMBARQUE ACEPTADA" << endl;
    cout << endl
         << "\t\t\t\tEspacio disponible en el buque: " << this->capacidad;

}

void Administracion::ejecutarAdministracion()
{

    // this->area();
    if (this->validacionDatos())
    {
        this->creacionContenedores();
    }
    else
    {
        cout << endl
             << "Operacion empresarial fallida..." << endl
             << endl;
        exit(1);
    }

    this->resumenDatos();
}
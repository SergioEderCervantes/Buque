#include "logistica.h"

Logistica::Logistica() : Administracion(){}

void Logistica::area(){

    cout<<endl<<endl<<"Entrando al area de logistica"<<endl;

}

void Logistica::ejecutarLogistica()
{
    this->mejorEmbarque();
}

Contenedor* Logistica:: generarCombinacionWin(Contenedor *vec, int n, int& valMax, int &elements, int capacidadBuque, int& volFinal, int& combinacionesHechas) {
    Contenedor *aux;
    for (int i = 0; i <( 1<<n); ++i) {
        Contenedor *combinacionActual= new Contenedor[n];
        int sumaActual = 0;
        int valorAct=0, cont=0;
        
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                if (sumaActual + vec[j].volumen <= capacidadBuque) {
                    combinacionActual[j]=vec[j];
                    sumaActual += vec[j].volumen;
                    valorAct += vec[j].costo;
                    combinacionesHechas++;
                    cont++;
                }
            }
        }

        if (valorAct > valMax) {
            aux=combinacionActual;
            valMax = valorAct;
            elements=cont;
        }
    }
    
    return aux;
}



void Logistica:: mejorEmbarque() {
    // Datos de ejemplo
    
    // Construir la lista doblemente ligada a partir de los datos
    
    int n=0, valMax=0, suma = 0, elements=0, volFinal =0;
    Contenedor *q = this->inicio;
    while (q!= NULL)
    {
        n+= q->unidades;
        q = q->der;
    }

    q = this->inicio;
    Contenedor *vec = new Contenedor[n];
    // Contenedor *combinacion = new Contenedor[1<<n];
    
    
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

    // Generar todas las combinaciones a partir del inicio de la lista
    Contenedor *convGanadora = generarCombinacionWin(vec,n,valMax,elements,this->getCapacidad(),volFinal);
    if (valMax != 0)
    {
        cout << endl << "Combinacion optima encontrada!!!!" << endl;
        cout << endl << "Precio total: " << valMax << " millones de peso";
        cout << endl << "Volumen ocupado: " << volFinal;
        cout << endl << endl << "Productos que formaran parte del embarque: " << endl << endl;

        convGanadora = cuentaArticulos(convGanadora, elements);
        for (int i = 0; i < elements; i++)
        {
            convGanadora[i].imprimirContenedor();
        }
        //llenarArchRes(convGanadora);
    }
    else
    {
        //llenarArchRes(0);
    }

    
    // Liberar la memoria de la lista

}
Contenedor* Logistica:: generarCombinacionWin(Contenedor* vec, int n,int& valMax, int& elements, int capacidadBuque, int& volFinal)
{
    Contenedor * convGanadora = new Contenedor[n];
    bool band = true;
    int acum = 0, i = 0;
    //Sacar todas las relaciones precio volumen de todo el vector
    for (int i = 0; i < n; i++)
    {

        vec[i].relacionPV = vec[i].getCosto() / vec[i].getVolumen();
    }
    vec = quickSort(vec,n);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (acum + vec[i].getVolumen() <= capacidadBuque)
        {
            convGanadora[j] = vec[i];
            elements++;
            valMax += vec[i].getCosto();
            acum += vec[i].getVolumen();
            j++;
        }        
    }
    volFinal = acum;
    return convGanadora;
}

Contenedor* Logistica:: quickSort(Contenedor *vec, int n)
{
    int i = 0, j = n - 1;
    Contenedor tmp;
    double pivot = vec[(i + j) / 2].relacionPV;
    while (i <= j)
    {
        while (vec[i].relacionPV > pivot)
            i++;
        while (vec[j].relacionPV < pivot)
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

void Logistica:: imprimirVectores(Contenedor* vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl << vec[i].getNombre();
    }
    
}

Contenedor* Logistica::cuentaArticulos(Contenedor *vec, int &n){
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n;) {
            if (vec[i].nombre == vec[j].nombre) {
                vec[i].unidades++;
                // Elimina el elemento duplicado desplazando los elementos restantes
                for (int k = j; k < n - 1; k++) {
                    vec[k] = vec[k + 1];
                    
                }
                n--;
            } else {
                j++;
            }
        }
    }
        
    return vec;
}
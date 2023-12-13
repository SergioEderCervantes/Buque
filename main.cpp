#include "administracion.cpp"
#include "logistica.cpp"
#include "buque.cpp"
using namespace std;

int main(){

    Puerto *Titanic=new Buque();

    Buque *embarque = static_cast<Buque*>(Titanic);
    embarque->ejecutarAdministracion();
    cout<<endl<<"-------------------------------------------"<<endl;
    embarque->mejorEmbarque();
    cout<<endl<<endl; 
    return 0;
}

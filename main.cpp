#include "logistica.cpp"
#include "buque.cpp"
using namespace std;

void menu();

int main(){
    menu();
    Puerto *Titanic=new Buque();

    Buque *embarque = static_cast<Buque*>(Titanic);

    
    embarque->ejecutarAdministracion();
    cout<<endl << endl <<"\t\t\t---------------------------------------------------"<<endl;
    embarque->ejecutarLogistica();
    cout<<endl<<endl;
    char c;
    cin >> c; 
    return 0;
}

void menu(){
    int opc = 0;

    do{
        cout<<"\t\t\t__________________________Menu__________________________"<<endl<<endl<<endl;
        cout<<"\t\t\t\t\t1. Iniciar Combinaciones"<<endl;
        cout<<"\t\t\t\t\t2. Manual de Usuario"<<endl;
        cin >>  opc;
        system("cls");
        if(opc==2){
            ifstream manual("manual.dat");
            manual.clear();
            manual.seekg(0);


            string linea;
            while (getline(manual, linea)) {
                cout << linea << endl;
            }
            system("pause");
            manual.close(); 
        }
        else{
            if(opc==1){
                cout << "\t\t\t\t\t\tIniciando..."<<endl;
                Sleep(2000);
            }
        }
        system("cls");
    }while(opc!=1);
    
}
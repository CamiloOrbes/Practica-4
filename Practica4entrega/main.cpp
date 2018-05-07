/*
- & = 1000 este es un cero relativo que indica que no hay conexion
- 1001 es un cero relativo que indica que el valor fue eliminado

* modelamiento de Red
* modelamiento de enrutador

Camilo Orbes Cabrera
Informatica II

*/

#include <red.h>// clase red
#include<enrutador.h> //clase enrutador
#include <iostream>
#include<string>
using namespace std;

int main()
{

    char inicio=' ';

    cout<<"Cargar Red(C) o Crear Red(N)"<<endl;
    cin>>inicio;
    cout<<"Al momento de ingresar el nombre de un enrutador utilice numeros para nombrarlos(0,1,2,etc...)  "<<endl;
    if(inicio=='C'){//cargar Red de un archivo

        Red A; // constructor por defecto cuando la red se carga desde un archivo
        A.Gen_Red('T');//carga de la red de un archivo
        A.MostrarRed();

        int ban =1;

        while(ban==1){ //menú

            string opcion="";
            cout<<"MENU PRINCIPAL"<<endl;
            cout<<endl;
            cout<<"-"<<"obtener conexiones de un enrutador: "<<"( enrutador )"<<endl;
            cout<<"-"<<"modificar la conexion entre dos enrutadores: ( modificar )"<<endl;
            cout<<"-"<<"obtener camino de un enrutador a otro: "<<"( camino )"<<endl;
            cout<<"-"<<"obtener el costo de ir de  un enrutador a otro: "<<"( costo )"<<endl;
            cout<<"-"<<"crear un nuevo enrutador: "<<"( crear )"<<endl;
            cout<<"-"<<"eliminar un enrutador : "<<"( eliminar )"<<endl;
            cin>>opcion;
            cout<<endl;

            if(opcion=="modificar"){

                Enrutador B;
                int E1;
                int E2;

                cout<<"ingrese enrutadores entre los que modificara un costo"<<endl;
                cin>>E1;
                cin>>E2;

                B.ModCosto(A,E1,E2);
                A.MostrarRed();

            }

            if (opcion=="enrutador"){

                Enrutador B;
                B.GenEnrt(A);
                B.MostrarEnrt(A);
            }

            if(opcion=="camino"){

                int _origen=0;
                int _destino=0;

                cout <<"ingrese el enrutador de origen: ";
                cin>>_origen;
                cout<<"ingrese el enrutador de destino: ";
                cin>>_destino;

                A.camino(_origen,_destino);}

            if(opcion=="costo"){

                int _origen=0;
                int _destino=0;

                cout <<"ingrese el enrutador de origen: ";
                cin>>_origen;
                cout<<"ingrese el enrutador de destino: ";
                cin>>_destino;

                A.Costo(_origen,_destino);}

            if(opcion=="crear"){

                char D;
                cout<<"valor manual (M) o aleatorio(A) ";
                cin>>D;

                A.Add_E(D);
                cout<<" se creo el nuevo enrutador"<<endl;
                A.MostrarRed();
            }

            if(opcion=="eliminar"){

                int enrt;
                cout<<"enrutador a  elminar ?: ";
                cin>>enrt;

                cout<<" se elmino el enrutador: "<<enrt<<endl;
                A.Pop_E(enrt);
                A.MostrarRed();

            }

            char D;

            cout<<"CONTINUAR?: (S/N): ";
            cin>>D;
            cout<<endl;
            if(D=='N'){ban=0;}
        }

        char guardar;
        cout<<"guardar Red?: (S/N) "; // opcion para guardar la matriz en un archivo de texto
        cin>>guardar;
        if(guardar=='S'){A.GuardarTabla();cout<<"Red guardada"<<endl;}

    }

    else if (inicio=='N'){//crear red aleatoria o manualmente

        int n=0;
        cout<<"ingrese el numero de enrutadores para su Red: "<<endl;// numero de enrutaddores
        cin>>n;

        char tipo=' ';
        cout<<"crear Red aleatoria (A) o crear Red manual(M)"<<endl; // generar una red manual o aleatoria
        cin>>tipo;

        if(tipo=='A'){

            Red A(n);//constructor cuando se crea la Red
            A.Gen_Red('A');//generacion de la Red aleatoria
            A.MostrarRed();

            int ban =1;

            while(ban==1){//menu

                string opcion="";
                cout<<"MENU PRINCIPAL"<<endl;
                cout<<endl;
                cout<<"-"<<"obtener conexiones de un enrutador: "<<"( enrutador )"<<endl;
                cout<<"-"<<"modificar la conexion entre dos enrutadores: ( modificar )"<<endl;
                cout<<"-"<<"obtener camino de un enrutador a otro: "<<"( camino )"<<endl;
                cout<<"-"<<"obtener el costo de ir de  un enrutador a otro: "<<"( costo )"<<endl;
                cout<<"-"<<"crear un nuevo enrutador: "<<"( crear )"<<endl;
                cout<<"-"<<"eliminar un enrutador de la red: "<<"( eliminar )"<<endl;
                cin>>opcion;
                cout<<endl;


                if(opcion=="modificar"){

                    Enrutador B;
                    int E1;
                    int E2;

                    cout<<"enrutadores entre los que modificara un costo"<<endl;
                    cin>>E1;
                    cin>>E2;

                    B.ModCosto(A,E1,E2);
                    A.MostrarRed();}

                if (opcion=="enrutador"){

                    Enrutador B;
                    B.GenEnrt(A);
                    B.MostrarEnrt(A);
                }

                if(opcion=="camino"){

                    int _origen=0;
                    int _destino=0;

                    cout <<"ingrese el enrutador de origen: ";
                    cin>>_origen;
                    cout<<"ingrese el enrutador de destino: ";
                    cin>>_destino;

                    A.camino(_origen,_destino);}

                if(opcion=="costo"){

                    int _origen=0;
                    int _destino=0;

                    cout <<"ingrese el enrutador de origen: ";
                    cin>>_origen;
                    cout<<"ingrese el enrutador de destino: ";
                    cin>>_destino;

                    A.Costo(_origen,_destino);}

                if(opcion=="crear"){

                    A.Add_E('A');
                    cout<<" se creo el nuevo enrutador"<<endl;
                    A.MostrarRed();
                }

                if(opcion=="eliminar"){

                    int enrt;
                    cout<<"enrutador a  elminar ?: ";
                    cin>>enrt;

                    cout<<" se elmino el enrutador: "<<enrt<<endl;
                    A.Pop_E(enrt);
                    A.MostrarRed();

                }

                char D;

                cout<<"CONTINUAR?: (S/N): ";
                cin>>D;
                cout<<endl;
                if(D=='N'){ban=0;}
            }

            char guardar;
            cout<<"guardar Red?: (S/N) ";// guardar Red en un archivo de texto
            cin>>guardar;
            if(guardar=='S'){A.GuardarTabla();cout<<"Red guardada"<<endl;}
        }

        else if(tipo=='M'){

            Red A(n);//constructor al crear una Red
            A.Gen_Red('M');// crear una red manualmente
            A.MostrarRed();

            int ban =1;

            while(ban==1){//menu

                string opcion="";
                cout<<"MENU PRINCIPAL"<<endl;
                cout<<endl;
                cout<<"-"<<"obtener conexiones de un enrutador: "<<"( enrutador )"<<endl;
                cout<<"-"<<"modificar la conexion entre dos enrutadores: ( modificar )"<<endl;
                cout<<"-"<<"obtener camino de un enrutador a otro: "<<"( camino )"<<endl;
                cout<<"-"<<"obtener el costo de ir de  un enrutador a otro: "<<"( costo )"<<endl;
                cout<<"-"<<"crear un nuevo enrutador: "<<"( crear )"<<endl;
                cout<<"-"<<"eliminar un enrutador de la red: "<<"( eliminar )"<<endl;
                cin>>opcion;
                cout<<endl;


                if(opcion=="modificar"){

                    Enrutador B;
                    int E1;
                    int E2;

                    cout<<"enrutadores entre los que modificara un costo"<<endl;
                    cin>>E1;
                    cin>>E2;

                    B.ModCosto(A,E1,E2);
                    A.MostrarRed();}

                if (opcion=="enrutador"){

                    Enrutador B;
                    B.GenEnrt(A);
                    B.MostrarEnrt(A);
                }

                if(opcion=="camino"){

                    int _origen=0;
                    int _destino=0;

                    cout <<"ingrese el enrutador de origen: ";
                    cin>>_origen;
                    cout<<"ingrese el enrutador de destino: ";
                    cin>>_destino;

                    A.camino(_origen,_destino);}

                if(opcion=="costo"){

                    int _origen=0;
                    int _destino=0;

                    cout <<"ingrese el enrutador de origen: ";
                    cin>>_origen;
                    cout<<"ingrese el enrutador de destino: ";
                    cin>>_destino;

                    A.Costo(_origen,_destino);}

                if(opcion=="crear"){

                    A.Add_E('M');
                    cout<<" se creo el nuevo enrutador"<<endl;
                    A.MostrarRed();
                }

                if(opcion=="eliminar"){

                    int enrt;
                    cout<<"enrutadora  elminar ?: ";
                    cin>>enrt;

                    cout<<" se elmino el enrutador: "<<enrt<<endl;
                    A.Pop_E(enrt);
                    A.MostrarRed();

                }

                char D;

                cout<<"CONTINUAR?: (S/N): ";
                cin>>D;
                cout<<endl;
                if(D=='N'){ban=0;}
            }

            char guardar;
            cout<<"guardar Red?: (S/N) ";//guardar la red en un archivo de texto
            cin>>guardar;

            if(guardar=='S'){A.GuardarTabla();cout<<"Red guardada"<<endl;}
            }

    }
}

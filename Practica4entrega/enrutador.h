#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include<red.h>
#include <iostream>
#include<vector>
using namespace std;

class Enrutador {

public:
    int tablaEnrt[100];
    void GenEnrt(Red n);
    void MostrarEnrt(Red n);
    void ModCosto(Red &n,int E1,int E2);
};

void Enrutador::GenEnrt(Red n){

    int enrt=0;
    cout<<"enrutador del que obtendra sus conexiones adyacentes: ";
    cin>>enrt;

    for(int i=0;i<n.nEnrutadores;i++){
        tablaEnrt[i]=n.tabla[enrt][i];
    }
}

void Enrutador::MostrarEnrt(Red n){
    for(int i=0;i<n.nEnrutadores;i++){
        cout<<tablaEnrt[i]<<' ';}cout<<endl;}

void Enrutador::ModCosto(Red &n,int E1, int E2){//...................

    int num;
    cout<<"ingrese el nuevo costo entre el enrutador "<<E1<<" y el enrutador "<<E2<<": ";
    cin>>num;

    n.tabla[E1][E2]=num;
    n.tabla[E2][E1]=num;


}


#endif // ENRUTADOR_H

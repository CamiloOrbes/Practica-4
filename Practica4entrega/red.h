#ifndef RED_H
#define RED_H

#include <string>
#include <iostream>
#include <fstream> //-----------librerias para  la implementacion de cada miembro de la clase Red
#include<vector>
#include<time.h>
using namespace std;

class Red{

public:

    Red(int _nEnrutadores);
    Red();   //------sobrecarga de constructores

    int nEnrutadores ; //numero de enrutadores
    int tabla[100][100];// Red cruda
    int copia[100][100];// Red con caminos minimos
    int recorrido[100][100]; // Red de caminos
    void Gen_Red(char tipo);// generacion de la red si se carga de un archivo o se crea
    void MostrarRed();//mostrar la matriz de caminos minimos en pantalla
    void camino(int origen,int destino);//camino de un enrutador origen a un destino
    void Costo(int origen,int destino);//costo de ir de un enrutador a otro
    void Add_E(char tip);//agregar un enrutador a la red
    void Pop_E(int enrt); //eliminar un enrutador de la red

    void GuardarTabla(); //almacenar una tabla e una archivo de texto

};

Red::Red(int _nEnrutadores){//constructor1

    nEnrutadores=_nEnrutadores;
}

Red::Red(){nEnrutadores=0;}//constructor por defecto

void Red::Gen_Red(char tipo){//generar Red


    if(tipo=='T'){ //generar red cargandola del archivo tabla.txt
        string texto;
        cout<<"digite el nombre del archivo de la topologia "<<endl;
        getline(cin,texto);
        getline(cin,texto);
        ifstream file;

        file.open(texto);

        string linea;

        int fila=0;
        int col=0;
        int nEn=0;

        while(!file.eof()){//lectura hasta fin del archivo

            getline(file,linea);//lectura de cada renglon del archivo

            for(unsigned int i=0;i<linea.length();i++){
                if(linea[i]=='&'){linea[i]=48;}
                if(linea[i]!=' '){tabla[fila][col]=linea[i]-'0';col++;}//conversion del valor en caracer a entero y asignacion en tabla
            }
            col=0;
            nEn+=1;//conteo de numero de enrutadores
            fila++;

        }

        nEnrutadores=nEn-1;// asignacion de el valor del numero de enrutadores

}

    if(tipo=='A'){ //generar red con costos aleatorios entre los enrutadores

        srand (time(NULL));
        int num=0;

        for (int fila=0;fila<nEnrutadores;fila++){
            int columna=0;
            for(int col=columna;col<nEnrutadores;col++){

                num = 0+rand()%(9-0);//numero aleatorio entre 0 y 9

                if(fila==col){tabla[fila][col]=0;}
                if(fila!=col){
                    tabla[fila][col]=num;
                    tabla[col][fila]=num;//formacion de matriz simetrica
                    }columna+=1;}
           }
    }

    if(tipo=='M'){ // generar red con costos entre enrutadores ingresados por consola

        int num=0;

        for (int fila=0;fila<nEnrutadores;fila++){
            int columna=0;
            for(int col=columna;col<nEnrutadores;col++){

                cout<<"posicion["<<fila<<"]["<<col<<"]"<<endl;
                cin>>num;//costo de el enrutador fila con el enrutador col

                if(fila==col){tabla[fila][col]=0;}
                if(fila!=col){
                    tabla[fila][col]=num;
                    tabla[col][fila]=num;}// mattriz simetrica
                    }columna+=1;}
    }

    for(int f=0;f<nEnrutadores;f++){
    for(int c=0;c<nEnrutadores;c++){
        if((tabla[f][c]==0)&&(f!=c)){tabla[f][c]=1000;}}//indicador de sin conexion entre enrutadores
    }

    for(int fila=0;fila<nEnrutadores;fila++){// matriz de recorridos
        for(int col=0;col<nEnrutadores;col++){
            if(fila==col){recorrido[fila][col]=1000;}
            else{recorrido[fila][col]=col;}}
    }

    for (int fila=0;fila<nEnrutadores;fila++){// matriz con costos minimos
                for(int col=0;col<nEnrutadores;col++){
                    copia[fila][col]=tabla[fila][col];}}

}

void Red::MostrarRed(){//mostrar tabla en pantalla

    int a;
    for (int i=0;i<nEnrutadores;i++){//mostrar tabla
        a=0;
        for (int j=0;j<nEnrutadores;j++){
            if (tabla[i][j]==1001){a++;cout<<"";}
            else if((tabla[i][j]==1000)&&(i!=j)){cout<<"& ";}
            else{cout<<tabla[i][j]<<" ";}

        }if (a==nEnrutadores) {cout<<"";}
        else{cout<<endl;}

    }cout<<"-----------------"<<endl;}

void Red::camino(int origen, int destino){//camino de enrutador origen a destino


    int puntas=1;
    int dcero=0;
    vector <int> via(100);
    int contador=0;

    while(puntas!=0){// se eliminan  los enrutadores con solo una conexion que sean diferentes de origen y destino

        puntas=0;

        for (int i=0;i<nEnrutadores;i++){

            for (int j=0;j<nEnrutadores;j++){

                if ((copia[i][j]!=0)&&(copia[i][j]!=1000)){dcero++;}

                if (dcero==2){break;}
            }
            if ((dcero==1)&&(i!=origen)&&(i!=destino)){

                for (int j=0;j<nEnrutadores;j++){copia[i][j]=0;}}
        }}

    int aux;
    //---------------algoritmo de  Floyd Warshall------------------

    for(int k=0;k<nEnrutadores;k++){//optimizacion de caminos
        for(int j=0;j<nEnrutadores;j++){
            for(int i=0;i<nEnrutadores;i++){
                aux=copia[j][k]+copia[k][i];
                if(copia[j][i]>aux){copia[j][i]=aux;recorrido[j][i]=k;}
            }
        }
    }

    cout<<" El camino de el enrutador : "<<origen<<" al " <<"enrutador "<<destino<<" es: "<<endl;


        while (origen!=destino){ // encontrar el camino de origen a destino desde la matriz de recorridso
                via[contador]=origen;
                cout<<via[contador]<<"  -  ";//imprimir caminon de origen a destino
                contador++;
                origen=recorrido[origen][destino];
            }
            via[contador]=destino;
            cout<<destino<<endl;

}

void Red::Costo(int origen,int destino){// costo de ir de origen a destino

    cout<<" El costo de ir de el enrutador : "<<origen<<" al " <<"enrutador "<<destino<<" es: ";
    cout<<copia[origen][destino]<<endl;// tomar la posicion [origen][destino] de la tabla de minimos costos
}

void Red::Add_E(char tip){

    nEnrutadores+=1;// actualizacion del numero de enrutadores de la red


    if(tip=='A'){//insertar valor manual
        int num;
        for(int fila=0;fila<nEnrutadores;fila++){//actualizacion de tabla
            num = 0 +rand()%(9-0);
            if (fila==nEnrutadores-1){tabla[fila][nEnrutadores-1]=0;}
            if(fila!=nEnrutadores-1){
                tabla[fila][nEnrutadores-1]=num;
                tabla[nEnrutadores-1][fila]=num;}
        }}

    if(tip=='M'){//insertar valor manual

        int num;
        for(int fila=0;fila<nEnrutadores;fila++){//actualizacion de tabla
            cout<<"ingrese el costo del enrutador "<<fila<<" con el enrutador: "<< nEnrutadores-1;
            cin>>num;
            if (fila==nEnrutadores-1){tabla[fila][nEnrutadores-1]=0;}
            if(fila!=nEnrutadores-1){
                tabla[fila][nEnrutadores-1]=num;
                tabla[nEnrutadores-1][fila]=num;}
        }

    }

    for(int fila=0;fila<nEnrutadores;fila++){
        for(int col=0;col<nEnrutadores;col++){
            copia[fila][col]=tabla[fila][col];}}//actualizacion de matriz de minimos costos

    for(int fila=0;fila<nEnrutadores;fila++){//actualizacion de matriz de recorridos
        for(int col=0;col<nEnrutadores;col++){
            if(fila==col){recorrido[fila][col]=1000;}
            else{recorrido[fila][col]=col;}

        }}
}

void Red::Pop_E(int enrt){

    for(int col=0;col<nEnrutadores;col++){
        tabla[enrt][col]=1001;
        tabla[col][enrt]=1001;}// modificacion de el valor en posicion [enrt][col] por un nulo relativo

    for(int fila=0;fila<nEnrutadores;fila++){//actualizacion de matriz de minimos costos
        for(int col=0;col<nEnrutadores;col++){
            copia[fila][col]=tabla[fila][col];}}

}

void Red::GuardarTabla(){
    string texto;
    cout<<"digite el nombre del archivo en el que desea guardar";
    getline(cin,texto);
    getline(cin,texto);
    ofstream file;
    file.open(texto);// tabla.txt en modo salida

    int a;
    for (int i=0;i<nEnrutadores;i++){//mostrar tabla
        a=0;
        for (int j=0;j<nEnrutadores;j++){
            if (tabla[i][j]==1001){a++;file<<"";}
            else if((tabla[i][j]==1000)&&(i!=j)){file<<"& ";}
            else{file<<tabla[i][j]<<" ";}

        }if (a==nEnrutadores) {file<<"";}
        else{file<<endl;}

    }
    file.close();
}

#endif // RED_H


//Librerias
#include <iostream>
#include <stdlib.h>
#include "dinero.h"

using namespace std;

int main()
{
    Dinero prueba;
    int i,opcion;

    do{


        std::cout<<"************************************************************************"<<std::endl;
        std::cout<<"**Introduzca un 1 entrar en el algoritmo voraz con monedas            **"<<std::endl;
        std::cout<<"**Introduzca un 2 entrar en el algoritmo voraz con billetes           **"<<std::endl;
        std::cout<<"**Introduzca un 3 entrar en el algoritmo voraz con billetes y monedas **"<<std::endl;
        std::cout<<"**Introduzca un 4 para salir                                          **"<<std::endl;
        std::cout<<"************************************************************************"<<std::endl;
        std::cout<<"Introduzca su opcion:";
        std::cin>>opcion;


        switch(opcion){

        case 1:

            cout<<"Introduzca su devolucion: ";
            cin>>prueba.devolucion_Monedas;
            //inicializacion de vector solucion
            for (i = 0; i < prueba.MONEDAS; i++){
                prueba.solucion.push_back(0);//relleno el bucle de soluciones con 0 para ir incrementando segun las monedas que use
            }
            prueba.voraz_Monedas();
            prueba.Funcion_Imprimir(prueba.MONEDAS);
            break;
        case 2:
            cout<<"Introduzca su devolucion: ";
            cin>>prueba.devolucion_Billetes;
            //inicializacion de vector solucion
            for (i = 0; i < prueba.BILLETES; i++){
                prueba.solucion_billetes.push_back(0);//relleno el bucle de soluciones con 0 para ir incrementando segun las monedas que use
            }
            prueba.voraz_Billetes();
            prueba.Funcion_Imprimir(prueba.BILLETES);

            break;
        case 3:
            cout<<"Introduzca su devolucion: ";
            cin>>prueba.devolucion_total;
            //inicializacion de vector solucion
            for (i = 0; i < prueba.Tam$; i++){
                prueba.solucion_total.push_back(0);//relleno el bucle de soluciones con 0 para ir incrementando segun las monedas que use
            }
            prueba.voraz_MonedasyBilletes();
            prueba.Funcion_Imprimir(prueba.Tam$);


            break;

        case 4:
            cout<<"Ha decidido salir"<<endl;

            break;
        default:
            cout<<"Ha decidido salir"<<endl;

            break;
        }
    }
    while(opcion<4);
    return 0;

}



//Librerias
#include <iostream>
#include <stdlib.h>
#include "fusion.h"



using namespace std;

int main()
{
    int opcion;
    Fusion prueba;
         do{


              cout<<"************************************************************************"<<endl;
              cout<<"**Introduzca un 1 para ordenar por fusion de forma recursiva          **"<<endl;
              cout<<"**Introduzca un 2 para ordenar por fusion de forma iterativa 	      **"<<endl;
              cout<<"**Introduzca un 3 para salir                                          **"<<endl;
              cout<<"************************************************************************"<<endl;
              cout<<"Introduzca su opcion:";
              cin>>opcion;


          switch(opcion){

        case 1:

          cout<<"Vector sin ordenar:";
          prueba.imprimir(prueba.vector,prueba.TAM,0);//llamamos a la funcion imprimir vector

          cout<<"Trazas de la ordenacion del vector mediante fusion"<<endl;
          prueba.fusionar(prueba.vector,0,prueba.TAM-1);//llamamos a la funcion fucionar para que empiece a dar los resultados

          cout<<"Vector ordenado:";
          prueba.imprimir(prueba.vector,prueba.TAM,0);//llamamos a la funcion imprimir vector


          break;
        case 2:
          cout<<"ALGORITMO ITERATIVO";//opcion extra sin terminar
          break;
        case 3:
              std::cout<<"Ha decidido salir"<<std::endl;

              break;
        default:
              std::cout<<"Ha decidido salir"<<std::endl;

              break;
          }
         }
    while(opcion < 3);
    return 0;
}


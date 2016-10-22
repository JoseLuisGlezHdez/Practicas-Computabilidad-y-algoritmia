#ifndef DINERO_H
#define DINERO_H

/*Definicion de librerias*/

#include <vector>
#include <list>

#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>



using namespace std;

class Dinero
{
public:
    Dinero();

    void Funcion_Seleccion(float, int , int var, int h);
    void Funcion_Imprimir(int);
    int Menu();
    void voraz_Monedas();
    void voraz_Billetes();
    void voraz_MonedasyBilletes();

    /***DEFINICION DE VECTORES****/

    vector <float> monedas;//vector donde guardare el valor de las monedas
    vector <int> billetes;//vector donde guardare el valor de los billetes
    vector <float> $;
    //int monedas[]= {200,100,50,20,10,5,2,1};//vector donde guardare el valor de las monedas
    //int billetes[]= {500,200,100,50,20,10,5};//vector donde guardare el valor de los billetes

    vector <float> solucion;//vector donde guardare el numero de monedas que usare
    vector <int>solucion_billetes;//vector donde guardare el numero de billetes que usare
    vector <float> solucion_total;//vector donde guardre el numero de monedas y billetes

    float devolucion_Monedas;
    int devolucion_Billetes;
    float devolucion_total;

    int MONEDAS;
    int BILLETES;
    int Tam$;
    float k;
    int h;


};

#endif // DINERO_H

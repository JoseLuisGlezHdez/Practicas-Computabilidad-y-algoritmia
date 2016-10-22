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

    void Funcion_Seleccion(int, int , int var, int );
    void Funcion_Imprimir(int);
    int Menu();
    void voraz_Monedas();
    void voraz_Billetes();
    void voraz_MonedasyBilletes();

    /***DEFINICION DE VECTORES****/

    vector <int> monedas;//vector donde guardare el valor de las monedas
    vector <int> billetes;//vector donde guardare el valor de los billetes
    vector <int> $;//vector donde guardare el valor de los billetes y monedas

    vector <int> solucion;//vector donde guardare el numero de monedas que usare
    vector <int>solucion_billetes;//vector donde guardare el numero de billetes que usare
    vector <int> solucion_total;//vector donde guardre el numero de monedas y billetes

    int devolucion_Monedas;
    int devolucion_Billetes;
    int devolucion_total;

    int MONEDAS;
    int BILLETES;
    int Tam$;
    int k;
    int h;





};

#endif // DINERO_H

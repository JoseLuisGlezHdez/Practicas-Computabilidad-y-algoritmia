#ifndef FUSION_H
#define FUSION_H


/*Definicion de librerias*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>


using namespace std;

class Fusion
{
public:
    Fusion();
    void fusionar(int vector[],int , int );
    void ordenarporfusion(int vector[],int ,int , int );
    void imprimir(int vector[],int ,int );

    int vector[13]={3,1,4,1,5,9,2,6,5,3,5,8,9};//vector predefinido
    int TAM=13;

};

#endif // FUSION_H

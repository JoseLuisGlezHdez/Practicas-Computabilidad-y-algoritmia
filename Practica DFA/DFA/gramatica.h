#ifndef GRAMATICA_H
#define GRAMATICA_H
#include "dfa.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

class Gramatica
{
public:
    Gramatica();

    char producciones[];
    char transiciones[100][100];
    vector<NODO> nodos_G;//vector nuevo para guardar la gramatica


    void crear_gramatica(DFA gramar);
    void exportar_gramatica(DFA gramar);
    void mostrar_gramatica(DFA gramar);
};

#endif // GRAMATICA_H

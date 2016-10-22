#ifndef NFA_H
#define NFA_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class TRANSICIONES {                       //Estructura que define los componentes de cada transición.
public:
    char SIMBOLO;                           //Componente Símbolo, que es el símbolo con el cual se activa la transición.
    int DESTINO;                            //Componente Destino, que es el lugar a donde va la transición
};


class NODO { //Estructura que define las componentes de un nodo.
public:
    unsigned int ID;                        //Identificador único del nodo.
    bool ACEPTACION;                        //Variable que determina si el nodo es un nodo de aceptación.
    int NTRANSICIONES;                      //Variable que determina cuantas transiciones tiene el nodo.
    vector<TRANSICIONES> TRANSICIONES_;     //Variable que indica cada una de las transiciones del nodo.

};

class NFA{

private:

    //Variables básicas
    int estados_;                               //Variable que indica cuántos estados tiene el DFA.
    int arranque_;                              //Variable que indica cuál es el nodo de arranque del DFA.
    vector<NODO> nodos_;                        //Vector que almacena todos los NODOS.

    //Funciones internas
    bool construirNFA(char nombreFichero[]);    //Función que construye el DFA a partir de un fichero.
    void mostrarEstadosMuerteNFA();                //Función que muestra los estados de muerte de el DFA.
    int simbolo(char s, int idd);               //Devuelve la transición que corresponde al símbolo s específicado en el nodo idd.


    //Variables internas
    vector<int> estadosMuerte_;                 //Vector que almacena todos los posibles estados de muerte del DFA.

public:
    //Constructor
    NFA();

    //Geters y Seters
    void set_estados(int e);
    void set_arranque(int a);
    void set_nodos(vector<NODO> &n);
    int get_estados();
    int get_arranque();
    vector<NODO>& get_nodos();

    //Funciones básicas
    bool leerNFA();                             //Función que lee un DFA, esta función llamará a construirDFA.
    void mostrarNFA();                          //Función que muestra el DFA tal y como está en el fichero.
    void identificarEstadosDeMuerteNFA();          //Función que identifica a los estados de Muerte.
    void analizarCadenaNFA();                      //Función que analiza una cadena para comprobar si pertenece o no al lenguaje del DFA.
};




#endif // NFA_H

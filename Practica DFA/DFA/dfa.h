/*********************************************************
 *******   PRACTICA 3 AUTOMATA FINITO DETERMINISTA  ******
 *******   Nombre:Jose Luis Gonzalez hernandez      ******
 *********************************************************/



#ifndef DFA_H
#define DFA_H

//Librerias

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
    char DESTINO_G;

};


using namespace std;

class NODO { //Estructura que define las componentes de un nodo.
public:
    unsigned int ID;                        //Identificador único del nodo.
    bool ACEPTACION;                        //Variable que determina si el nodo es un nodo de aceptación.
    int NTRANSICIONES;                      //Variable que determina cuantas transiciones tiene el nodo.
    vector<TRANSICIONES> TRANSICIONES_;     //Variable que indica cada una de las transiciones del nodo.


};

class DFA{

private:

    //Variables básicas
    int estados_;                               //Variable que indica cuántos estados tiene el DFA.
    int arranque_;                              //Variable que indica cuál es el nodo de arranque del DFA.
    vector<NODO> nodos_;                        //Vector que almacena todos los NODOS.
    vector<NODO> terminales;                    //Vector donde guardare los estados terminales.
    vector<NODO> no_terminales;                 //Vector donde guardare los estados no terminales.
    vector<NODO> divisiones;                    //Vector donde guardare los estados que salgan de terminales y no terminales.

    //Funciones internas
    bool construirDFA(char nombreFichero[]);    //Función que construye el DFA a partir de un fichero.
    void mostrarEstadosMuerte();                //Función que muestra los estados de muerte de el DFA.
    int simbolo(char s, int idd);               //Devuelve la transición que corresponde al símbolo s específicado en el nodo idd.
    bool repiteTransiciones();                  //Comprueba que no se repiten transiciones con el mismo símbolo por cada nodo.
    bool diferentesNuTransiciones();            //Comprueba que no hay nodos con diferente número de transiciones.

    //Variables internas
    vector<int> estadosMuerte_;                 //Vector que almacena todos los posibles estados de muerte del DFA.

public:

    //Constructor
    DFA();
   int n;                                       //numero de transiciones global
   int tam_terminales,tam_noterminales,tam_divisiones;//tamaño de los vectores
   int x;

    //Geters y Seters
    void set_estados(int e);
    void set_arranque(int a);
    void set_nodos(vector<NODO> &n);
    int get_estados();
    int get_arranque();
    vector<NODO>& get_nodos();


    //Funciones básicas
    bool leerDFA();                             //Función que lee un DFA, esta función llamará a construirDFA.
    void mostrarDFA();                          //Función que muestra el DFA tal y como está en el fichero.
    void identificarEstadosDeMuerte();          //Función que identifica a los estados de Muerte.
    void analizarCadena();                      //Función que analiza una cadena para comprobar si pertenece o no al lenguaje del DFA.
    void minimizar_DFA();                       //Minimiza el DFA
    void particionar(int);                      //particiona los vectores
    void mostrar_minimizacion(int);             //Muestra el dfa minimizado
    void crear_nuevo_DFA();                     //crea el dfa a partir del dfa minimizado.
    void exportar_DFA_Minimo();

};


#endif // DFA_H

/*********************************************************
 *******   PRACTICA 3 AUTOMATA FINITO DETERMINISTA  ******
 *******   Nombre:Jose Luis Gonzalez hernandez      ******
 *********************************************************/

//Librerias
#include <iostream>
#include <stdlib.h>
#include "dfa.h"
#include "funciones.h"
#include "gramatica.h"


//Funcion main

int main()
{
    DFA prueba;                             //Crea un objeto tipo DFA.
    Gramatica gramar;
    int x=0;
    bool definido = false;                  //Variable definido que determina si ya se ha cargado un DFA en el objeto desde un archivo o no.
    int opcion, salida = 0;                 //Variables para controlar la salida del programa y las opciones del menú.
    while (salida == 0) {                   //Mientras la variable salida sea 0, se muestra el menú.
        mostrarMenu(definido);              //Función que muestra el menú, definido en Funciones.h
        cin >> opcion;                      //Se almacena en opción la opción del menú que escoja el usuario.
        if (definido == true) {             //Controla las opciones que se recogen si el DFA ha sido cargado en el objeto o no.
            switch (opcion) {
                case 1:
                    //system ("clear");
                    if (prueba.leerDFA() == true){                      //Función del objeto que lee un DFA desde un fichero.
                        definido = true;
                    }

                    break;
                case 2:
                    //system ("clear");
                    prueba.mostrarDFA();                                //Función que muestra el DFA según estaba definido en el fichero.
                    break;
                case 3:
                    //system ("clear");
                    prueba.identificarEstadosDeMuerte();                //Función que identifica los estados de muerte
                    break;
                case 4:
                    //system ("clear");
                    prueba.analizarCadena();                            //Función que permite introducir una cadena y determinar si pertenece al lenguaje
                    break;                                              //Descrito por el DFA.
                case 5:
                     prueba.particionar(x);
                     break;
                case 6:
                     prueba.exportar_DFA_Minimo();
                     break;
                case 7:
                     gramar.crear_gramatica(prueba);
                     break;
                case 8:
                     gramar.mostrar_gramatica(prueba);
                     break;
                case 9:
                    gramar.exportar_gramatica(prueba);
                    break;
                case 0:
                    //system ("clear");
                    cout << "Adiós!" << endl;
                    salida = 1;                                         //Si la entrada es 0, se sale del programa.
                    break;
            default:                                                //En caso de que no se inserte nada correspondiente al menú, se vuelve a pedir datos.
                    //system ("clear");
                    cout << "Inserte una opción aceptable..." << endl;
                    break;
            }
        } else {                            //A continuación es el caso de que no se haya cargado aún ningún DFA en el objeto.
            switch (opcion) {
                case 1:
                    //system ("clear");
                    prueba.leerDFA();                                   //Función del objeto que lee un DFA desde un fichero.
                    definido = true;
                    break;
                case 2:
                    //system ("clear");
                    cout << "Adiós!" << endl;
                    salida = 1;                                         //Si la entrada es 2, se sale del programa.
                    break;
                default:                                                //En caso de que no se inserte nada correspondiente al menú, se vuelve a pedir datos.
                    //system ("clear");
                    cout << "Inserte una opción aceptable..." << endl;
                    break;
            }
        }
    }
    return 0;
}



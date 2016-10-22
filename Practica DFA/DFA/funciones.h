/*********************************************************
 *******   PRACTICA 3 AUTOMATA FINITO DETERMINISTA  ******
 *******   Nombre:Jose Luis Gonzalez hernandez      ******
 *********************************************************/

#ifndef FUNCIONES_H
#define FUNCIONES_H

void mostrarMenu(bool definido) {
    if (definido) {
        cout << "1. Leer DFA" << endl;
        cout << "2. Mostrar DFA" << endl;
        cout << "3. Identificar estados de muerte" << endl;
        cout << "4. Analizar cadena" << endl;
        cout << "5. Minimizar DFA" << endl;
        cout << "6. Exportar DFA minimo" << endl;
        cout << "7. Crear Gramatica" << endl;
        cout << "8. Mostrar Gramatica" << endl;
        cout << "9. Exportar Gramatica" << endl;
        cout << "0. Salir" << endl;
    } else {
        cout << "1. Leer DFA" << endl;
        cout << "2. Salir" << endl;
    }
}


#endif // FUNCIONES_H

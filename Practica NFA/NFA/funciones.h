#ifndef FUNCIONES_H
#define FUNCIONES_H

void mostrarMenu(bool definido) {
    if (definido) {
        cout << "1. Leer NFA" << endl;
        cout << "2. Mostrar NFA" << endl;
        cout << "3. Identificar estados de muerte NFA" << endl;
        cout << "4. Analizar cadena NFA" << endl;
        cout << "5. Salir" << endl;
    } else {
        cout << "1. Leer NFA" << endl;
        cout << "2. Salir" << endl;
    }
}



#endif // FUNCIONES_H

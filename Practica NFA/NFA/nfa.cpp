#include "nfa.h"


//CONSTRUCTOR
NFA::NFA() : estados_(0), arranque_(0), nodos_(NULL){ }
//GETERS Y SETERS

void NFA::set_estados(int e){
    estados_ = e;
}
void NFA::set_arranque(int a){
    arranque_ = a;
}
void NFA::set_nodos(vector<NODO> &n){   //Introduce todo el vector de nodos que se le pase en el objeto DFA.

    nodos_.resize(n.size());
    for (int i = 0; i < estados_; i++) {
        nodos_[i].ID = n[i].ID;
        nodos_[i].ACEPTACION = n[i].ACEPTACION;
        nodos_[i].NTRANSICIONES = n[i].NTRANSICIONES;
        nodos_[i].TRANSICIONES_.resize(n[i].NTRANSICIONES);

        for (int j = 0; j < nodos_[i].NTRANSICIONES; i++) {
            nodos_[i].TRANSICIONES_[j].DESTINO = n[i].TRANSICIONES_[j].DESTINO;
            nodos_[i].TRANSICIONES_[j].SIMBOLO = n[i].TRANSICIONES_[j].SIMBOLO;

        }
    }
}
int NFA::get_estados(){
    return estados_;
}
int NFA::get_arranque(){
    return arranque_;
}
vector<NODO>& NFA::get_nodos(){         //Devuelve el vector de nodos completo
    return nodos_;
}
//FUNCIONES BÁSICAS
bool NFA::leerNFA(){
    char a[50];
    cout << "Introduzca el nombre del fichero a cargar" << endl;
    cin >> a;
    return construirNFA(a);

}
void NFA::mostrarNFA(){                 //Muestra el DFA.
    cout << estados_ << endl;
    cout << arranque_ << endl;
    for (int i = 0; i < get_estados(); i++) {
        cout << nodos_[i].ID << " " << nodos_[i].ACEPTACION << " " << nodos_[i].NTRANSICIONES;
        for (int j = 0; j < nodos_[i].NTRANSICIONES; j++) {
            cout << " " << nodos_[i].TRANSICIONES_[j].SIMBOLO << " " << nodos_[i].TRANSICIONES_[j].DESTINO;
        }
        cout << endl;
    }
}
void NFA::identificarEstadosDeMuerteNFA(){
    estadosMuerte_.resize(0);
    bool iguales = false;
    for (int i = 0; i < estados_; i++) {
        if (nodos_[i].ACEPTACION == false) {
            if (arranque_ != nodos_[i].ID) {
                iguales = false;
                for (int j = 0; j < nodos_[i].NTRANSICIONES; j++) {
                    if (nodos_[i].TRANSICIONES_[j].DESTINO != nodos_[i].ID) {
                        iguales = true;
                        j=nodos_[i].NTRANSICIONES;


                    }
                }
                if (iguales == false) {
                       estadosMuerte_.push_back(nodos_[i].ID);                                         //Es un estado de muerte.
                }
             }
         }
    }

    mostrarEstadosMuerteNFA();                                                                             //Muestra los estados de muerte
}
void NFA::analizarCadenaNFA(){

    string a;
    cout << "introduce la cadena para analizarla" << endl;
    cin >> a;
    cout << "Cadena de entrada: ";
    for (int i=0; i<a.length(); i++) {
        cout << a[i];
    }
    cout << endl;
    //////////////////////////////////////////////////////////////////Primera fase, comprobar que los símbolos de la cadena pertenecen al alfabeto
    bool esta_en_lenguaje = true;
    int p1 = 0;
    for (int y = 0; y < a.size(); y++) {
        p1 = 0;
        for (int x = 0; x < nodos_[0].NTRANSICIONES; x++) {
            if (a[y] != nodos_[0].TRANSICIONES_[x].SIMBOLO) {
                //cout << a[y] << "!=" << nodos_[0].TRANSICIONES[x].SIMBOLO << endl;
                p1 = p1+1;

            }
        }
        //cout << p1 << endl;
        if (p1 == 2) {
            //cout << "No está en el lenguaje" << endl;
            esta_en_lenguaje = false;
        }
    }
    //////////////////////////////////////////////////////////////////Segunda fase, comprobar que cumple el DFA.
    if (esta_en_lenguaje == true) {
        int i = 1; int siguiente;
        cout << "ESTADO ACTUAL " << "ENTRADA " << "ESTADO SIGUIENTE" << endl;
        siguiente = nodos_[arranque_].TRANSICIONES_[simbolo(a[0], arranque_)].DESTINO;//simplemente me muestra el primer estado
        cout <<  arranque_ << "             " << a[0] << "       " << siguiente << endl;

        for ( std::string::iterator it=a.begin(); it!=a.end()-1; ++it ) {   //Recorre toda la cadena
            bool muerte = false;
            for (int j = 0; j < estadosMuerte_.size(); j++) {               //Comprueba si el siguiente estado es un estado de muerte
                if (nodos_[siguiente].ID == estadosMuerte_[j]) {
                    muerte = true;
                }
            }
            int mostrar = siguiente;
            if (muerte == false) {                                          //Si no es un estado de muerte se muestra la transición
                siguiente = nodos_[siguiente].TRANSICIONES_[simbolo(a[i], siguiente)].DESTINO;
                cout <<  mostrar << "             " << a[i] << "       " << siguiente << endl;
            } else {                                                        //Si es un estado de muerte la cadena es inválida
                cout << "Estado de Muerte! Secuencia Inválida" << endl;
                it=a.end()-2;
            }
            i++;
        }
        if (nodos_[siguiente].ACEPTACION == true) {                         //Si acaba la cadena y está en un estado de aceptación, es aceptada.
            cout << "Cadena de entrada: ACEPTADA" << endl;
        } else {                                                            //Si no la cadena es rechazada.
            cout << "Cadena de entrada: RECHAZADA" << endl;
        }
    } else {
        cout << "Esta cadena contiene símbolos que no son del alfabeto del DFA" << endl;
    }

}
//FUNCIONES INTERNAS
bool NFA::construirNFA(char nombreFichero[]){   //Recorre todo el fichero y almacena el DFA en el objeto DFA.

    fstream texto(nombreFichero);
    //texto.open(nombreFichero);
    if (texto.is_open()) {
        cout<<"Archivo abierto"<<endl;
        texto >> estados_;
        texto >> arranque_;
        nodos_.resize(estados_);
        for (int i = 0; i < estados_; i++) {
            texto >> nodos_[i].ID >> nodos_[i].ACEPTACION >> nodos_[i].NTRANSICIONES;
            nodos_[i].TRANSICIONES_.resize(nodos_[i].NTRANSICIONES);
            for (int j = 0; j < nodos_[i].NTRANSICIONES; j++) {
                texto >> nodos_[i].TRANSICIONES_[j].SIMBOLO;
                texto >> nodos_[i].TRANSICIONES_[j].DESTINO;

            }
        }
    }texto.close();

    return true;
}
void NFA::mostrarEstadosMuerteNFA(){               //Muestra los estados de Muerte previamente identificados.
    if (estadosMuerte_.size() > 0) {
        for (int i = 0; i < estadosMuerte_.size(); i++) {
            cout << "Estado de muerte nº" << i+1 << " en el estado: " << estadosMuerte_[i] << endl;
        }
    } else {
        cout << "No hay estados de muerte" << endl;
    }
}
int NFA::simbolo(char s, int idd){  //Devuelve la transición que corresponde al símbolo s específicado en el nodo idd.
    //cout << "símbolo: " << s << endl;
    for (int i = 0; i < nodos_[idd].NTRANSICIONES; i++) {
        if (s == nodos_[idd].TRANSICIONES_[i].SIMBOLO) {

            return i;
        }
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////




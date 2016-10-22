/*********************************************************
 *******   PRACTICA 3 AUTOMATA FINITO DETERMINISTA  ******
 *******   Nombre:Jose Luis Gonzalez hernandez      ******
 *********************************************************/

//Librerias

#include "dfa.h"

//CONSTRUCTOR
DFA::DFA() : estados_(0), arranque_(0), nodos_(NULL){
    tam_divisiones=0;
    tam_noterminales=0;
    tam_terminales=0;
    x=0;
}
//GETERS Y SETERS

void DFA::set_estados(int e){
    estados_ = e;
}
void DFA::set_arranque(int a){
    arranque_ = a;
}
void DFA::set_nodos(vector<NODO> &n){   //Introduce todo el vector de nodos que se le pase en el objeto DFA.

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

int DFA::get_estados(){
    return estados_;
}
int DFA::get_arranque(){
    return arranque_;
}
vector<NODO>& DFA::get_nodos(){         //Devuelve el vector de nodos completo
    return nodos_;
}

//FUNCIONES BÁSICAS
bool DFA::leerDFA(){
    char a[50];
    cout << "Introduzca el nombre del fichero a cargar" << endl;
    cin >> a;
    return construirDFA(a);
    //más cosas de control...
}
void DFA::mostrarDFA(){                 //Muestra el DFA.
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
void DFA::identificarEstadosDeMuerte(){
    estadosMuerte_.resize(0);
    for (int i = 0; i < estados_; i++) {
        if (nodos_[i].ACEPTACION == false) {
            if (arranque_ != nodos_[i].ID) {
                bool iguales = false;
                for (int j = 1; j < nodos_[i].NTRANSICIONES; j++) {                                     //Si las transiciones del nodo van al mismo lugar.
                    if (nodos_[i].TRANSICIONES_[j].DESTINO == nodos_[i].TRANSICIONES_[j-1].DESTINO) {
                        iguales = true;
                    } else {
                        iguales = false;
                        //Aquí debería acabarse el for.
                        j =nodos_[i].NTRANSICIONES; //Esto te saca del for.
                    }
                }
                if (iguales == true) {
                    if (nodos_[i].TRANSICIONES_[0].DESTINO == nodos_[i].ID) {                            //Y ese lugar es el mismo nodo.
                        estadosMuerte_.push_back(nodos_[i].ID);                                         //Es un estado de muerte.
                    }
                }
            }
        }
    }
    mostrarEstadosMuerte();                                                                             //Muestra los estados de muerte
}
void DFA::analizarCadena(){
    //char a[200];
    string a;
    cout << "introduce la cadena para analizarla" << endl;
    cin >> a;
    cout << "Cadena de entrada: ";
    for (int i=0; i<a.length(); ++i) {
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
        siguiente = nodos_[arranque_].TRANSICIONES_[simbolo(a[0], arranque_)].DESTINO;
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
bool DFA::construirDFA(char nombreFichero[]){   //Recorre todo el fichero y almacena el DFA en el objeto DFA.

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
            n=nodos_[i].NTRANSICIONES;
            for (int j = 0; j < nodos_[i].NTRANSICIONES; j++) {
                texto >> nodos_[i].TRANSICIONES_[j].SIMBOLO;
                texto >> nodos_[i].TRANSICIONES_[j].DESTINO;

            }
        }
    }texto.close();
    if (repiteTransiciones() == true && diferentesNuTransiciones() == true) {   //Detección de errores.
        cout << "DFA Erróneo!!" << endl;
        return false;
    }


    return true;
}
void DFA::mostrarEstadosMuerte(){               //Muestra los estados de Muerte previamente identificados.
    if (estadosMuerte_.size() > 0) {
        for (int i = 0; i < estadosMuerte_.size(); i++) {
            cout << "Estado de muerte nº" << i+1 << " : " << estadosMuerte_[i] << endl;
        }
    } else {
        cout << "No hay estados de muerte" << endl;
    }
}
int DFA::simbolo(char s, int idd){  //Devuelve la transición que corresponde al símbolo s específicado en el nodo idd.
    //cout << "símbolo: " << s << endl;
    for (int i = 0; i < nodos_[idd].NTRANSICIONES; i++) {
        if (s == nodos_[idd].TRANSICIONES_[i].SIMBOLO) {
            //cout << s << " es igual a : " << nodos_[idd].TRANSICIONES[i].SIMBOLO << endl;
            return i;
        }
    }
    return 0;
}
bool DFA::repiteTransiciones(){     //Recorre cada nodo y comprueba si tiene más de una transición con el mismo símbolo.
    vector<char> prueba;            //Almacenará los símbolos usados en las transiciones de los nodos
    for (int i = 0; i < estados_; i++) {
        prueba.resize(0);
        for (int j = 1; j < nodos_[i].NTRANSICIONES; j++) {
            prueba.push_back(nodos_[i].TRANSICIONES_[j].SIMBOLO);
        }
        for (int j = 0; j < prueba.size(); j++) {
            for (int k = j+1; k < prueba.size(); k++) {
                if (prueba[j] == prueba[k]) {
                    return true;
                }
            }
        }
    }
    return false;
}
bool DFA::diferentesNuTransiciones(){   //Comprueba uno a uno todos los nodos si tienen el mismo número de transiciones.
    int prueba;
    prueba = nodos_[0].NTRANSICIONES;
    for (int i = 0; i < estados_; i++) {
        if (nodos_[i].NTRANSICIONES != prueba) {
            return true;
        } else {
            prueba = nodos_[i].NTRANSICIONES;
        }
    }
    return false;
}

void DFA::minimizar_DFA(){

    int tam_divisiones2=tam_divisiones;
    int tam;
    int hay_divisiones=0;
    int dif=0,igu=0;


    tam=tam_divisiones;
    hay_divisiones=0;

     for (int k = 0; k < n; k++){//aki miramos y probamos con un simbolo
        if(hay_divisiones==0){
          cout<<"Con el simbolo '"<<nodos_[k].TRANSICIONES_[k].SIMBOLO<<"'"<<endl;

          for(int i = 0;i < tam_terminales;i++){//recorremos los terminales
              dif=0;
              igu=0;
              for(int j=0 ; j <tam_terminales; j++){
                  if(terminales[i].TRANSICIONES_[k].DESTINO != terminales[j].TRANSICIONES_[k].DESTINO){
                    dif++;
                  }
                  if(terminales[i].TRANSICIONES_[k].DESTINO == terminales[j].TRANSICIONES_[k].DESTINO){
                    igu++;
                  }

              }
              if(dif >= 1 && igu <= 1){
                  divisiones.push_back(terminales[i]);
                  hay_divisiones=1;
                  tam_divisiones++;

              }
          }
          for(int i = 0;i < tam_noterminales;i++){//recorremos los terminales
              dif=0;
              igu=0;
              for(int j=0 ; j <tam_noterminales; j++){
                  if(no_terminales[i].TRANSICIONES_[k].DESTINO != no_terminales[j].TRANSICIONES_[k].DESTINO){
                    dif++;
                  }
                  if(no_terminales[i].TRANSICIONES_[k].DESTINO == no_terminales[j].TRANSICIONES_[k].DESTINO){
                    igu++;
                  }

              }
              if(dif >= 1 && igu <= 1){
                  divisiones.push_back(no_terminales[i]);
                  hay_divisiones=1;
                  tam_divisiones++;

              }
          }


        }
      }

        x++;
        if(tam_divisiones != tam){
            cout<<"entro en particionar"<<endl;
            particionar(x);

        }
        else{
            cout<<"FIN DE MINIMIZACION"<<endl;
            mostrar_minimizacion(-1);

        }

}
void DFA::particionar(int x){
int bandera=0;

    if(x==0){//particionamos sin divisiones dividimos en dos el vector , en terminales y no terminales
        for (int i = 0; i < estados_; i++) { //separamos los estados en dos array

            if(nodos_[i].ACEPTACION == 1){
                terminales.push_back(nodos_[i]);
                tam_terminales++;
            }
            else{
                no_terminales.push_back(nodos_[i]);
                tam_noterminales++;
            }
        }

    }
    else{// particionamos
        tam_terminales=0;
        tam_noterminales=0;

        for (int i = 0; i < estados_; i++) { //separamos los estados en dos array
            bandera=0;
            for(int j = 0; j < tam_divisiones;j++){
                if(nodos_[i].ID == divisiones[j].ID){
                    bandera=1;
                }
             }
                if(nodos_[i].ACEPTACION == 1 && bandera==0){
                        terminales.insert(terminales.begin()+tam_terminales,tam_terminales+1,nodos_[i]);
                        bandera=1;
                        tam_terminales++;
                }
                else
                    if(nodos_[i].ACEPTACION == 0 && bandera==0){
                            no_terminales.insert(no_terminales.begin()+tam_noterminales,tam_noterminales+1,nodos_[i]);
                            tam_noterminales++;
                            bandera=1;
                    }
            }
        }



    mostrar_minimizacion(x);

}

void DFA::mostrar_minimizacion(int x){
    char a;
  if(x==-1){
     cout<<"P("<<"M"<<"){";
     if(tam_terminales >= 1){
         cout<<"{";
         for(int j = 0;j < tam_terminales;j++){
            cout<<terminales[j].ID;
            if(j != tam_terminales-1)
                cout<<",";
         }
         cout<<"},";
         tam_terminales=1;
     }
      if(tam_divisiones >= 1){

          for(int j = 0; j < tam_divisiones;j++){
              cout<<"{"<<divisiones[j].ID<<"}";
              cout<<",";
          }
      }
      if(tam_noterminales >= 1){
          cout<<"{";
          for(int j = 0; j < tam_noterminales;j++){
              cout<<no_terminales[j].ID;
              if(j != tam_noterminales-1)
                  cout<<",";
          }
          cout<<"}";
          tam_noterminales=1;
      }
      cout<<"}"<<endl;

      cout<<"El DFA tiene "<<(tam_divisiones+tam_noterminales+tam_terminales)<<" estados."<<endl;
      crear_nuevo_DFA();
  }
  else{
    cout<<"P("<<x<<"){";
    cout<<"{";
    for(int j = 0;j < tam_terminales;j++){
       cout<<terminales[j].ID;
       if(j != tam_terminales-1)
           cout<<",";
    }
    cout<<"},";
    if(x!=0){
        cout<<"{";
        for(int j = 0; j < tam_divisiones;j++){
            cout<<divisiones[j].ID;
            if(j != tam_divisiones-1)
                cout<<",";
        }
        cout<<"},";
    }
    cout<<"{";
    for(int j = 0; j < tam_noterminales;j++){
        cout<<no_terminales[j].ID;
        if(j != tam_noterminales-1)
            cout<<",";
    }
    cout<<"}}"<<endl;

    //cin>>a;
    minimizar_DFA();
  }
}

void DFA::crear_nuevo_DFA(){
    cout<<"entro en crear"<<endl;
    int numero_estados=(tam_divisiones+tam_noterminales+tam_terminales);
    int min=100,min2=100,j=0;
    int bandera=0;
    int numero[numero_estados];
    int l=0;
    if(numero_estados != estados_){

        for(int j = 0;j < tam_terminales;j++){//encontramos el estado menor
            if(terminales[j].ID < min){

                min=terminales[j].ID;
               // numero[l]=min;
                cout<<"min1:"<<min<<endl;

            }
            if(arranque_==terminales[j].ID){
                arranque_=min;

            }

        }
        //l++;
        for(int j = 0;j < tam_noterminales;j++){//encontramos el estado menor
            if(no_terminales[j].ID < min2){
                //numero[l]=min2;
                min2=no_terminales[j].ID;
            }
            if(arranque_==no_terminales[j].ID){
                arranque_=min2;
            }
        }
        //l=0;
        for(int j = 0;j < tam_terminales;j++){
            if(tam_terminales<=1){
                //min=numero[l];
                //l++;
                //cout<<"min1f:"<<min<<endl;
            }
        }

        for(int j = 0;j < tam_noterminales;j++){
            if(tam_noterminales<=1){
                //min2=numero[l];
                //l++;
            }
        }
      for (int k = 0; k < n; k++){
          for(int j = 0; j < tam_divisiones ; j++ ){
              cout<<"nodo divi:"<<divisiones[j].ID<<endl;
                for(int i = 0; i < tam_terminales; i++ ){
                    cout<<"nodo ter:"<<terminales[i].ID<<endl;
                  if(divisiones[j].TRANSICIONES_[k].DESTINO == terminales[i].ID){
                      cout<<"destino antes:"<<divisiones[j].TRANSICIONES_[k].DESTINO<<endl;
                      divisiones[j].TRANSICIONES_[k].DESTINO = min;
                      cout<<"destino despues:"<<divisiones[j].TRANSICIONES_[k].DESTINO<<endl;
                      cout<<"min:"<<min<<endl;
                  }
              }
          }
      }

      for(int i = 0; i < numero_estados ; i++ ){//creamos el nuevo nodo
          if(bandera==0){
            if(tam_terminales>=1){
                nodos_.insert(nodos_.begin()+numero_estados,numero_estados+1,terminales[min]);
                i++;
            }
            if(tam_terminales>=1){
                nodos_.insert(nodos_.begin()+numero_estados,numero_estados+1,terminales[min2]);
                i++;
            }
            bandera=1;

          }
          nodos_.insert(nodos_.begin()+numero_estados,numero_estados+1,divisiones[j]);
          j++;



      }

    }
    //prueba
    estados_=numero_estados;
    for (int i = 0; i < estados_; i++) {
        cout << nodos_[i].ID << " " << nodos_[i].ACEPTACION << " " << nodos_[i].NTRANSICIONES;
        for (int j = 0; j < nodos_[i].NTRANSICIONES; j++) {
            cout << " " << nodos_[i].TRANSICIONES_[j].SIMBOLO << " " << nodos_[i].TRANSICIONES_[j].DESTINO;
        }
        cout << endl;
    }
}

void DFA::exportar_DFA_Minimo(){
    ofstream fs("minimo.dfa");
    fs<<estados_<<endl;
    fs<<arranque_<<endl;

    for(int i=0;i<estados_;i++){
        fs<<nodos_[i].ID<<" ";
        fs<<nodos_[i].ACEPTACION<<" ";
        fs<<nodos_[i].NTRANSICIONES<<" ";

        for (int j = 0; j < nodos_[i].NTRANSICIONES; j++) {
            fs<<nodos_[i].TRANSICIONES_[j].SIMBOLO<<" ";
            fs<<nodos_[i].TRANSICIONES_[j].DESTINO<<" ";
        }
        fs<<endl;
    }


    fs.close();

}

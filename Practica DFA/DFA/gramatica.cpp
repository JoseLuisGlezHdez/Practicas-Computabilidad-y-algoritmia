#include "gramatica.h"
#include "dfa.h"

Gramatica::Gramatica()
{

}

void Gramatica::crear_gramatica(DFA gramar){

   nodos_G=gramar.get_nodos();//copio en nodosG el nodo de dfa
   int m;

   producciones[gramar.get_estados()];

   int j=65;//para empezar en la A

   for(int i=0;i<gramar.get_estados();i++){//guardamos en producciones las letras de los estados
       if(i==gramar.get_arranque())
           producciones[i]='S';
       else{
           producciones[i]=j;
           j++;
        }
   }
   //cambiando el nodo
   for (int i = 0; i < gramar.get_estados(); i++) {
       if(nodos_G[i].ACEPTACION==1){
           nodos_G[i].ACEPTACION=='126';
       }
       for (int j = 0; j < nodos_G[i].NTRANSICIONES; j++) {
            m=nodos_G[i].TRANSICIONES_[j].DESTINO;
            nodos_G[i].TRANSICIONES_[j].DESTINO_G=producciones[m];//DESTINO_G ES PARA QUE SEA DE TIPO CHAR Y NO INT COMO ERA EL OTRO.
        }
   }




}

void Gramatica::exportar_gramatica(DFA gramar){

    ofstream fs("gramatica.grm");
    fs<<gramar.n<<endl;
    for (int j = 0; j < nodos_G[0].NTRANSICIONES; j++) {
        fs<<nodos_G[0].TRANSICIONES_[j].SIMBOLO;
        fs<<" ";
    }
    fs<<endl;
    fs<<gramar.get_estados()<<endl;
    for(int i=0;i<gramar.get_estados();i++){
         fs<<producciones[i];
         fs<<" ";
     }
    fs<<endl;
    for(int i=0;i<gramar.get_estados();i++){
        fs<<producciones[i];
        fs<<"->";
         for (int j = 0; j < nodos_G[i].NTRANSICIONES; j++) {
             fs<<nodos_G[i].TRANSICIONES_[j].SIMBOLO;
             fs<<nodos_G[i].TRANSICIONES_[j].DESTINO_G;
             fs<<"|";

         }
         if(nodos_G[i].ACEPTACION==1){
             fs<<"~"<<endl;
         }
         else
             fs<<endl;


    }


    fs.close();

}


void Gramatica::mostrar_gramatica(DFA gramar){

    cout<<gramar.n<<endl;
    for (int j = 0; j < nodos_G[0].NTRANSICIONES; j++) {
        cout<<nodos_G[0].TRANSICIONES_[j].SIMBOLO;
        cout<<" ";
    }
    cout<<endl;
    cout<<gramar.get_estados()<<endl;
    for(int i=0;i<gramar.get_estados();i++){
         cout<<producciones[i];
         cout<<" ";
     }
    cout<<endl;
    for(int i=0;i<gramar.get_estados();i++){
        cout<<producciones[i];
        cout<<"->";
         for (int j = 0; j < nodos_G[i].NTRANSICIONES; j++) {
             cout<<nodos_G[i].TRANSICIONES_[j].SIMBOLO;
             cout<<nodos_G[i].TRANSICIONES_[j].DESTINO_G;
             cout<<"|";

         }
         if(nodos_G[i].ACEPTACION==1){
             cout<<"€"<<endl;
         }
         else
             cout<<endl;


    }


}

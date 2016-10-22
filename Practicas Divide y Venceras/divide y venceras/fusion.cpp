#include "fusion.h"


using namespace std;

Fusion::Fusion()
{

}


/***************FUNCION FUSION ********************/
void Fusion::fusionar(int vector[],int i, int t){

  int m;

  if(i!=t){//comprovamos que nuestro indice no ha llegado al final.
    m=(i+t)/2;//dividimos el tamaño del vector para ordenarlo mediante los indices
    fusionar(vector,i,m);//llamamos de forma recursiva a la funcion para que vuelva a dividir
    fusionar(vector,m+1,t);////llamamos de forma recursiva a la funcion para que vuelva a dividir pasandole la otra mitad
    ordenarporfusion(vector,i,m,t);//llamamos a la funcion ordenar para ir ordenando las mitades
  }

}

/***************FUNCION ORDENAR POR FUSION ********************/
void Fusion::ordenarporfusion(int vector[],int i,int m, int t){

  int aux[m-i+1];
  int j,k,V1=0,V2=m+1;
  bool verbose = false;//SI ESTA A TRUE MOSTRAR LA TRAZA DE LA ORDENACION




  for(j=i;j<=m;j++)
    aux[j-i]=vector[j];


  for(j=i;j<=t;j++){
    if(aux[V1] < vector[V2]){
      vector[j]=aux[V1++];
      verbose=true;
      if(V1==m-i+1){
    for(k=V2;k<=t;k++)
      vector[++j]= vector[k];
      }
    }
    else{
      verbose=true;
      vector[j]=vector[V2++];

      if(V2==t+1){
    verbose=true;
    for(k=V1;k<=m-i;k++)
      vector[++j]=aux[k];
      }
    }
    if(verbose==true)
      imprimir(vector,t+1,0);
  }

}

/***********FUNCION IMPRIMIR VECTOR ****************/

void Fusion::imprimir(int vector[],int t,int i){


  cout<<"[";
  for(i;i<t;i++){
        cout<<vector[i]<<" ";

      }
  cout<<"]"<<endl;
}

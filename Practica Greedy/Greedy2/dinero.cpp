#include "dinero.h"

using namespace std;

Dinero::Dinero()
{
   MONEDAS=8;
   BILLETES=7;
   Tam$=15;

  monedas.push_back(200);
  monedas.push_back(100);
  monedas.push_back(50);
  monedas.push_back(20);
  monedas.push_back(10);
  monedas.push_back(5);
  monedas.push_back(2);
  monedas.push_back(1);

  billetes.push_back(500);
  billetes.push_back(200);
  billetes.push_back(100);
  billetes.push_back(50);
  billetes.push_back(20);
  billetes.push_back(10);
  billetes.push_back(5);

  $.push_back(50000);
  $.push_back(20000);
  $.push_back(10000);
  $.push_back(5000);
  $.push_back(2000);
  $.push_back(1000);
  $.push_back(500);
  $.push_back(200);
  $.push_back(100);
  $.push_back(50);
  $.push_back(20);
  $.push_back(10);
  $.push_back(5);
  $.push_back(2);
  $.push_back(1);


}
/***************FUNCION VORAZ******************************/

void Dinero::voraz_Monedas(){
    //bucle voraz
    if(devolucion_Monedas <= 0)
        cout<<"No existe solucion"<<endl;
    else{

        for (int i = 0; i < MONEDAS; i++)
        {
            k=monedas[i];
            Funcion_Seleccion(k,i,MONEDAS,h);

        }

        cout<<endl;
        //fin del bucle voraz

    }


}


void Dinero::voraz_Billetes(){
    //bucle voraz
    if(devolucion_Billetes < 5)
        cout<<"No existe solucion"<<endl;
    else{

        for (int i = 0; i < BILLETES; i++)
        {
            h=billetes[i];
            Funcion_Seleccion(k,i,BILLETES,h);

        }
        cout<<endl;
        //fin del bucle voraz

    }
}


void Dinero::voraz_MonedasyBilletes(){
    //bucle voraz

    if(devolucion_total < 0)
        cout<<"No existe solucion"<<endl;
    else{

        for (int i = 0; i < Tam$; i++)
        {
            k=$[i];
            Funcion_Seleccion(k,i,Tam$,h);

        }
        cout<<endl;

        //fin del bucle voraz

    }
}

/***************FUNCION SELECCION******************************/

void  Dinero::Funcion_Seleccion(int k, int i, int var, int h)
{ //cout<<"Funcion_Seleccion:"<<endl;


   if(var==MONEDAS){
    while (devolucion_Monedas >= k)//mientras la devolucion no sea igual o mayor que la moneda del vector
    {
            solucion[i]++;//aumento una moneda

            devolucion_Monedas = (devolucion_Monedas - k);//le resto a la devolucion la moneda que seleccione segun la posicion del indice en el vector
    }
   }
   else
   if(var==BILLETES){
       while (devolucion_Billetes >= h)//mientras la devolucion no sea igual o mayor que la moneda del vector
       {
               solucion_billetes[i]++;//aumento una moneda
               devolucion_Billetes = devolucion_Billetes - h;//le resto a la devolucion la moneda que seleccione segun la posicion del indice en el vector
       }

   }
   else
   if(var==Tam$){

       while (devolucion_total>= k)//mientras la devolucion no sea igual o mayor que la moneda del vector
       {
           cout<<devolucion_total<<endl;
               solucion_total[i]++;//aumento una moneda
               devolucion_total = devolucion_total - k;//le resto a la devolucion la moneda que seleccione segun la posicion del indice en el vector
       }

   }


}

/***************FUNCION IMPRIMIR*********************************/

void Dinero::Funcion_Imprimir(int TAM)
{
cout<<"Funcion_Imprimir:"<<endl;
int suma=0;
  if(TAM==MONEDAS){
      if (devolucion_Monedas <  0) //Si existe devolucion , osea si es !0
             cout<<"No existe solucion"<<endl;
          else
             //mostramos la solucion

             for (int i = 0; i < TAM; i++)//recorro el vector de nuevo para mostrar la solucion final
             {
                 if(monedas[i]>=100){
                     if(monedas[i]==200)
                     cout<<"modenas de 2€:->"<<solucion[i]<<endl;
                     else
                     cout<<"modenas de 1€:->"<<solucion[i]<<endl;
                 }
                     else
                     cout<<"modenas de "<< monedas[i]<<"c:->"<<solucion[i]<<endl;
             }
      for(int i=0;i<MONEDAS;i++){
          suma=solucion[i]+suma;
      }
      cout<<"El numero de monedas usadas son:"<<suma<<endl;
  }else
  if(TAM==BILLETES){
      if (devolucion_Billetes <  0) //Si existe devolucion , osea si es !0
         cout<<"No existe solucion"<<endl;
      else
         //mostramos la solucion

         for (int i = 0; i < TAM; i++)//recorro el vector de nuevo para mostrar la solucion final
         {
          cout<<"billetes de "<< billetes[i]<<"€:->"<<solucion_billetes[i]<<endl;
          }
      for(int i=0;i<BILLETES;i++){
          suma=solucion_billetes[i]+suma;
      }
      cout<<"El numero de Billetes usados son:"<<suma<<endl;
  }else
      if(TAM==Tam$){
          cout<<"imprimir"<<endl;
          if (devolucion_total <  0) //Si existe devolucion , osea si es !0
             cout<<"No existe solucion"<<endl;
          else
             //mostramos la solucion

             for (int i = 0; i < TAM; i++)//recorro el vector de nuevo para mostrar la solucion final
             {
              if($[i]>=500){
              cout<<"billetes de "<< $[i]/100<<"€:->"<<solucion_total[i]<<endl;
              }
              else
                  if($[i]>=100){
                      if($[i]==200)
                      cout<<"modenas de 2€:->"<<solucion_total[i]<<endl;
                      else
                      cout<<"modenas de 1€:->"<<solucion_total[i]<<endl;
                   }
                   else
                      cout<<"modenas de "<< $[i]<<"c:->"<<solucion_total[i]<<endl;
              }
          for(int i=0;i<Tam$;i++){
              suma=solucion_total[i]+suma;
          }
          cout<<"El numero de monedas y billetes usados son:"<<suma<<endl;
      }




}

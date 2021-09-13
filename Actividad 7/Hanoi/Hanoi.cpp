#include<iostream>
#include"Pila.h"
#include"assertdomjudge.h"
using namespace std;

void Hanoi(int n, Pila *origen, Pila *destino, Pila *temporal){
  assertdomjudge(n > 0);
  if (n == 1){
    destino->apilar(origen->desapilar());
  }else{
    Hanoi(n - 1, origen, temporal, destino);
    destino->apilar(origen->desapilar());
    Hanoi(n - 1, temporal, destino, origen);
  }
}

int main(){  
  Pila *A=new Pila("A");
  Pila *B=new Pila("B");
  Pila *C=new Pila("C");

  int n;
  cin>>n;

  for(int i=n;i>0;i--)
    A->apilar(i);

  Hanoi(n,A,C,B);
  
  for(int i=0;i<n;i++)
    C->desapilar();

  return 0;
}


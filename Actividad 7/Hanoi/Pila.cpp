#include"Pila.h"
#include "assertdomjudge.h"

Pila::Pila(string name){
  this->cima = NULL;
  this->name = name;
}

std::string Pila::nombrePila(){
  return name;
}

void Pila::apilar(int num){
  Nodo *temp = new Nodo(num, cima);
  cima = temp;
  cout<<"Apilando disco "<<num<<" en poste "<<name<<endl;
}
  
int Pila::desapilar(){
  assertdomjudge(cima != NULL);    
  Nodo *temp;
  temp = cima;
  cima = temp->siguiente;
  int num = temp->valor;
  delete temp;
  cout<<"Desapilando disco "<<num<<" del poste "<<name<<endl;
  return num;
}

bool Pila::estaVacia(){
  if(cima == NULL){
    return true;
  }else{
    return false;
  }
}
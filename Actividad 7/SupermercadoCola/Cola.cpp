#include "Cola.h"

Cola::Cola(){
    this->principio = NULL;
    this->final = NULL;
}

void Cola::encolar(int num){
    Nodo *temp = new Nodo(num);

    if(this->principio == NULL){
        this->principio = temp;
        this->final = temp;
    }else {
        this->final->siguiente = temp;
        this->final = temp;
    }
}

int Cola::desencolar(){
    Nodo *temp = this->principio;
    int valor = temp->valor;

    if(temp->siguiente == NULL){
        this->principio = NULL;
        this->final = NULL;
    } else this->principio = temp->siguiente;

    delete temp;
    return valor;
}

bool Cola::estaVacia(){
    return (this->principio == NULL) ? true : false;
}
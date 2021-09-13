#include "ListaEnlazada.h"
#include <iostream>
#include "assertdomjudge.h"

using namespace std;

ListaEnlazada::ListaEnlazada(){
    n = 0;
    lista = NULL;
}

ListaEnlazada::~ListaEnlazada(){
    Nodo *temp = lista;

    for (int i = 0; i < n; i++)
    {
        delete temp;
        temp = temp->siguienteNodo;
    }
}

Nodo * ListaEnlazada::getNodo(int posicion){
    assertdomjudge(0 <= posicion && posicion < n);

    Nodo *temp = lista;

    for (int i = 0; i < posicion; i++){
        temp = temp->siguienteNodo;
    }

    return temp;
}

int ListaEnlazada::getValor(int posicion){
    assertdomjudge(0 <= posicion && posicion < n);

    return getNodo(posicion)->elemento;
}

void ListaEnlazada::setValor(int posicion, int nuevoValor){
    assertdomjudge(0 <= posicion && posicion < n);

    getNodo(posicion)->elemento = nuevoValor;
}

int ListaEnlazada::getN(){
    return n;
}

void ListaEnlazada::insertar(int posicion, int nuevoValor){
    assertdomjudge(posicion <= n);

    Nodo *temp = new Nodo;

    this->n++;

    if (lista == NULL){
        temp->elemento = nuevoValor;
        temp->siguienteNodo = NULL;
        this->lista = temp;

    } else{

        if (posicion == 0){
            temp->elemento = nuevoValor;
            temp->siguienteNodo = lista;
            this->lista = temp;

        } else if (posicion == n){
            temp->elemento = nuevoValor;
            temp->siguienteNodo = NULL;
            getNodo(posicion - 1)->siguienteNodo = temp;

        } else{
            temp->elemento = nuevoValor;
            temp->siguienteNodo = getNodo(posicion - 1)->siguienteNodo;
            getNodo(posicion - 1)->siguienteNodo = temp;
        }
    }
}

void ListaEnlazada::eliminar(int posicion){
    assertdomjudge(0 <= posicion && posicion < n);

    this->n--;

    if (posicion == 0){
        this->lista = lista->siguienteNodo;

    } else if (posicion == n){
        getNodo(posicion - 1)->siguienteNodo = NULL;

    } else{
        getNodo(posicion - 1)->siguienteNodo = getNodo(posicion + 1);
    }
}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar){

    Nodo *temp = lista;

    for (int i = 0; i < n - 1; i++){
        temp = temp->siguienteNodo;
    }

    temp->siguienteNodo = listaAConcatenar->lista;
    n = n + listaAConcatenar->n;
}

int ListaEnlazada::buscar(int elementoABuscar){
    Nodo *temp = lista;

    for (int i = 0; i < n; i++){
        if (temp->elemento != elementoABuscar){
            temp = temp->siguienteNodo;
        } else {
            return i;
        }
    }
    return -1;
}
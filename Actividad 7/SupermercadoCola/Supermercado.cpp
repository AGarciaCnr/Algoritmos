#include "Supermercado.h"

Supermercado::Supermercado(int n){
    this->n_cajas = n;
    this->cajas = new Cola[n];
}

void Supermercado::nuevoUsuario(int n, int id){
    this->cajas[n].encolar(id);
}

int Supermercado::atenderUsuario(int n){
    return this->cajas[n].desencolar();
}

bool Supermercado::cajaVacia(int n){
    return this->cajas[n].estaVacia();
}

void Supermercado::cerrarCaja(int n){
    for(int i = 0; !cajaVacia(n); i++){
        if(i == n_cajas) i = 0;
        if(i == n) i++;
        nuevoUsuario(i, atenderUsuario(n));
    }
}
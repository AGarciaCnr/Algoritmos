#include "Supermercado.h"
#include "assertdomjudge.h"

Supermercado::Supermercado(int n){
    this->n_cajas = n;
    this->cajas = new ColaPrioridad[n];
}

void Supermercado::nuevoUsuario(int n, int id){
    this->cajas[n].encolar(id);
}

void Supermercado::cerrarCaja(int n){
    assertdomjudge(n >= 0 && this->n_cajas);

    int i = 0;

    while(!this->cajas[n].estaVacia()){
        if(i == n)
            i++;
        if(i == n_cajas)
            i = 0;
        int temp = this->cajas[n].desencolar();
        this->cajas[i].encolar(temp);
        i++;
    }
}

int Supermercado::atenderUsuario(int n){
    return this->cajas[n].desencolar();
}

bool Supermercado::cajaVacia(int n){
    return this->cajas[n].estaVacia();
}
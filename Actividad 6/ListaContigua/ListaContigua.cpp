#include "ListaContigua.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <stdio.h>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

ListaContigua::ListaContigua(int incremento){
	this->vector = new int[incremento];
    this->n = 0;
    this->capacidad = incremento;
	this->incremento = incremento;
}
		
ListaContigua::~ListaContigua(){
    delete[] this->vector;
}
		
int ListaContigua::getValor(int posicion){
	assertdomjudge(this->n > posicion);
    return this->vector[posicion];
}
		
void ListaContigua::setValor(int posicion, int nuevoValor){
    assertdomjudge(this->n > posicion);
    this->vector[posicion] = nuevoValor;
}
		
int ListaContigua::getN(){
	return this->n;
}
		
int ListaContigua::getCapacidad(){
	return this->capacidad;
}		
		
void ListaContigua::insertar(int posicion, int nuevoValor){
	assertdomjudge(posicion <= this->n);
	this->n++;

	if(this->n > capacidad || posicion + 1 > capacidad){
		capacidad += incremento;
		this->vector = (int*) realloc (vector, sizeof(int) * capacidad);
	}	
	
	if(posicion + 1 > this->n) this->n = posicion + 1;

    memmove(this->vector + posicion + 1, this->vector + posicion, sizeof(int) * (this->n - posicion - 1));
    this->vector[posicion] = nuevoValor;
}
		
void ListaContigua::eliminar(int posicion){
	assertdomjudge(posicion < this->n);
	this->n--;

    memmove(this->vector + posicion, this->vector + posicion + 1, sizeof(int) * (this->n - posicion));

    if(this->n <= (capacidad - 2 * incremento)){
		capacidad -= incremento;
        this->vector = (int *)realloc(this->vector, sizeof(int) * capacidad);
    }
}
		
void ListaContigua::concatenar(ListaContigua *lista){
	if(this->n + lista->n > this->capacidad){
		this->capacidad += lista->capacidad;
        this->vector = (int *)realloc(this->vector, sizeof(int) * this->capacidad);

        memmove(this->vector + n, lista->vector, sizeof(int) * lista->n);
        this->n += lista->n;
	} else {
		memmove(this->vector + this->n, lista->vector, sizeof(int) * lista->n);
	}
	
}

int ListaContigua::buscar(int elementoABuscar){
	assertdomjudge(this->n > 0);
	for(int i = 0; i < this->n; i++)
		if( *(this->vector + i) == elementoABuscar) return i;
	return -1;
}
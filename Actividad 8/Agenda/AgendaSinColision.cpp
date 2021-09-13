#include "Agenda.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

Agenda::Agenda(int capacidad){
	assertdomjudge(capacidad > 0);
	this->capacidad = capacidad;
	this->nombres = new string[capacidad];
	this->telefonos = new long[capacidad];
	this->ocupados = new bool[capacidad];

	for(int i = 0; i < capacidad; i++){
		nombres[i] = "";
		telefonos[i] = 0;
		ocupados[i] = false;
	}
}

Agenda::~Agenda(){
	delete [] nombres;
	delete [] telefonos;
	delete [] ocupados;
}

int Agenda::obtenerPosicion(long telefono){
	return telefono % capacidad;
}

bool Agenda::existeContacto(long telefono){
	if((ocupados[obtenerPosicion(telefono)]) && telefonos[obtenerPosicion(telefono)] == telefono){
		return true;
	}else{
		return false;
	}
}

string Agenda::getContacto(long telefono){
	assertdomjudge(existeContacto(telefono));
	return nombres[telefono % capacidad];
}

void Agenda::introducirContacto(long telefono, string contacto){
	assertdomjudge(!existeContacto(telefono) && !ocupados[obtenerPosicion(telefono)]);
	nombres[obtenerPosicion(telefono)] = contacto;
	telefonos[obtenerPosicion(telefono)] = telefono;
	ocupados[obtenerPosicion(telefono)] = true;
}

void Agenda::eliminarContacto(long telefono){
	assertdomjudge(existeContacto(telefono));
	ocupados[obtenerPosicion(telefono)] = false;
}
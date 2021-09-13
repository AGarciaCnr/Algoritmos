#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}


//Asignacion de matrices

Matriz::Matriz(int n_filas, int n_columnas){
  this -> n_filas = n_filas;
  this -> n_columnas = n_columnas;

  if(n_filas == 0 && n_columnas == 0){
    matriz = NULL;
  }else{
    matriz = new double* [n_filas];

    for(int i = 0; i < n_filas; i++){
      matriz[i] = new double [n_columnas];
    }
  }
}

Matriz::Matriz(const Matriz &m){}

Matriz::~Matriz(){}

Matriz Matriz::operator +(const Matriz &m){
  assertdomjudge((this->n_filas == m.n_filas) && (this->n_columnas == m.n_columnas) && (this->n_filas > 0) && (m.n_filas > 0) && (this->n_columnas > 0) && (m.n_columnas > 0));
  
  Matriz m2(this->n_filas, this->n_columnas);
  
  for(int i = 0; i < this->n_filas; i++){
    for(int j = 0; j < this->n_columnas; j++){
      m2.matriz[i][j] = this->matriz[i][j] + m.matriz[i][j];
    }
  }
  
  return m2;
}
  
Matriz Matriz::operator -(const Matriz &m){
  assertdomjudge((this->n_filas == m.n_filas) && (this->n_columnas == m.n_columnas) && (this->n_filas > 0) && (m.n_filas > 0) && (this->n_columnas > 0) && (m.n_columnas > 0));  
  
  Matriz m2(this->n_filas, this->n_columnas);
  
  for(int i = 0; i < this->n_filas; i++){
    for(int j = 0; j < this->n_columnas; j++){
      m2.matriz[i][j] = this->matriz[i][j] - m.matriz[i][j];
    }
  }
  
  return m2;
}

Matriz Matriz::operator *(double n){
  assertdomjudge((this->n_filas > 0) && (this->n_columnas > 0));
  
  Matriz m2(this->n_filas, this->n_columnas);

  for(int i = 0; i < this->n_filas; i++){
    for(int j = 0; j < this->n_columnas; j++){
      m2.matriz[i][j] = this->matriz[i][j] * n;
    }
  }
  
  return m2;
}

Matriz Matriz::operator *(const Matriz &m){
  assertdomjudge((this->n_columnas == m.n_filas) && (this->n_filas > 0) && (m.n_filas > 0) && (this->n_columnas > 0) && (m.n_columnas > 0));  
  
  Matriz m2(this->n_filas, m.n_columnas);
  
  for(int i = 0; i < this->n_filas; i++){
    for(int j = 0; j < m.n_columnas; j++){
      for(int interior = 0; interior < this->n_columnas; interior++ ){
        m2.matriz[i][j] += this->matriz[i][interior] * m.matriz[interior][j];
      }
    }
  }
  
  return m2;
}

Matriz Matriz::calcularTraspuesta(){
  assertdomjudge((this->n_filas > 0) && (this->n_columnas > 0));
  
  Matriz m2(this->n_columnas, this->n_filas);

  for(int i = 0; i < this->n_columnas; i++){
    for(int j = 0; j < this->n_filas; j++){
      m2.matriz[i][j] = this->matriz[j][i];
    }
  }
  
  return m2;
}
  
bool Matriz::esSimetrica(){
  assertdomjudge((this->n_filas > 0) && (this->n_columnas > 0) && (this->n_filas == this->n_columnas));

  for(int i = this->n_filas - 1; i > 0; i--){
    for(int j = this->n_columnas - 2; j > -1; j--){
      if(this->matriz[i][j] != this->matriz[j][i]){
        return false;
      }
    }
  }

  return true;
}

double Matriz::obtenerMaximo(){
  assertdomjudge((this->n_filas > 0) && (this->n_columnas > 0));
  
  double temp = this->matriz[0][0];
  
  for(int i = 0; i < this->n_filas; i++){
    for(int j = 0; j < this->n_columnas; j++){
      if(this->matriz[i][j] > temp){
        temp = this->matriz[i][j];
      }
    }
  }

  return temp;
}

double Matriz::obtenerMinimo(){
  assertdomjudge((this->n_filas > 0) && (this->n_columnas > 0));
  
  double temp = this->matriz[0][0];
  
  for(int i = 0; i < this->n_filas; i++){
    for(int j = 0; j < this->n_columnas; j++){
      if(this->matriz[i][j] < temp){
        temp = this->matriz[i][j];
      }
    }
  }

  return temp;
}

Matriz& Matriz::operator= (const Matriz &m)
{
  if(matriz!=NULL)
    {
      for (int i = 0; i < n_filas; i++)
	    delete[] matriz[i];
      
      delete[] matriz;
      matriz=NULL;
    }

  this->n_filas=m.n_filas;
  this->n_columnas=m.n_columnas;
  this->matriz=NULL;

  if(n_filas>0 && n_columnas>0)
    {
      matriz= new double *[n_filas];
  
      for (int i = 0; i < n_filas; i++)
      {
        matriz[i] = new double[n_columnas];  
        for(int j=0; j <n_columnas; j++)
          matriz[i][j]=m.matriz[i][j];
      }
    }
  
    return(*this); 
}

// Leer matriz
void Matriz::rellenarManual()
{
  double elemento;
  for (int i = 0; i < n_filas; i++)
    {
      cout << "Fila " << i << endl;
      for (int j = 0; j < n_columnas; j++)
	      {
          cout << "Elemento " << j  << endl;
          cin >> elemento;
          matriz[i][j] = elemento;
        }
      cout << endl;
    }
  
}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
  srand(seed);
  for (int i = 0; i < n_filas; i++)
    for (int j = 0; j < n_columnas; j++)
      matriz[i][j]=rand();
  
}

// Imprimir Matriz
void Matriz::mostrarMatriz()
{
  for (int i = 0; i < n_filas; i++)
    {
      for (int j = 0; j < n_columnas; j++)
        cout << matriz[i][j] << " ";       
      cout << endl;
    }
}
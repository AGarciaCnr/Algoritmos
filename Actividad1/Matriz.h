#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
 private:
  double **matriz;
  
  int n_filas;
  int n_columnas;

 public:

  Matriz(int n_filas = 0, int n_columnas = 0);

  Matriz(const Matriz &m);

  ~Matriz();

  Matriz operator +(const Matriz &m);
  
  Matriz operator -(const Matriz &m);

  Matriz operator *(double n);

  Matriz operator *(const Matriz &m);

  Matriz calcularTraspuesta();
  
  bool esSimetrica();

  double obtenerMaximo();

  double obtenerMinimo();

/* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
	   Parámetro: la matriz que se va a asignar
	   Retorno: una nueva matriz con la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

  Matriz& operator= (const Matriz &m);


/* Permite rellenar todos los elementos de la matriz del objeto actual preguntando al usuario 
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/
  
  void rellenarManual();


/* Permite rellenar todos los elementos de la matriz del objeto actual de forma aleatoria 
	   Parámetro: semilla que se utiliza para el generador aleatorio
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

  void rellenarAleatorio(long seed);



/* Imprime por pantalla todos los elementos de la matriz del objeto actual  
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

  void mostrarMatriz();

};

#endif // MATRIZ_H

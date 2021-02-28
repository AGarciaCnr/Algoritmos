#include<iostream>
using namespace std;

void ordenarSeleccion(int x[], int len)
{
    for (int i = 0; i < len; i++)
    {
        /*Añadir código de ordenar mediante selección */

        int aux, min;
        min = i;

        for (int j = i + 1; j < len; j++) {
            if (x[j] < x[min]) {
                min = j;
            }
        }
       
        aux = x[i];
        x[i] = x[min];
        x[min] = aux;

        /*No tener en cuenta el siguiente bucle de impresion  para el calculo de la complejidad*/
        for (int k = 0; k < len; k++)
            cout << x[k] << " ";
        cout << endl;
    }
}



int main()
{
    int n;
    cin >> n;
    int* x = new int[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    ordenarSeleccion(x, n);
}

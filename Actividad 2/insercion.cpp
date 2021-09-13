#include<iostream>
using namespace std;

void ordenarBurbuja(int x[], int len) {
    for (int i = 1; i < len; i++) {
        /*Añadir código de ordenación usando algoritmo de burbuja*/

        int aux = x[i];
        int j = i - 1;

        while ((x[j] > aux) && (j >= 0)) {
            x[j + 1] = x[j];
            j--;
        }

        x[j + 1] = aux;

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
    ordenarBurbuja(x, n);
}

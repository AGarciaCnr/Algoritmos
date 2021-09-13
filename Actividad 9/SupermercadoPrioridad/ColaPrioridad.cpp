#include "ColaPrioridad.h"
#include "assertdomjudge.h"

void ColaPrioridad::encolar(int num){
    vector.insertarAlFinal(num);

    int posicion = vector.getN() - 1, valor = vector.getValor(posicion);

    bool seguir = true;

    while(posicion > 0 && seguir){
        if (posicion & 1){
            if (valor < vector.getValor((posicion - 1) / 2))
            {
                int temp;
                temp = vector.getValor((posicion - 1) / 2);
                vector.setValor((posicion - 1) / 2, valor);
                vector.setValor(posicion, temp);
            }
            else
                seguir = false;
        }else{
            if (valor < vector.getValor((posicion / 2) - 1))
            {
                int temp;
                temp = vector.getValor((posicion / 2) - 1);
                vector.setValor((posicion / 2) - 1, valor);
                vector.setValor(posicion, temp);
            }
            else
                seguir = false;
        }
    }
}

int ColaPrioridad::desencolar(){
    assertdomjudge(!this->estaVacia());

    int valor = vector.getValor(0);
    
    vector.setValor(0, vector.getValor(vector.getN() - 1));
    vector.eliminarAlFinal();
    
    if(vector.getN() != 0)
        this->reestructurar();
    
    return valor;
}

bool ColaPrioridad::estaVacia(){
    if(vector.getN() == 0)
        return true;
    else
        return false;
}

void ColaPrioridad::reestructurar(){
    int valor = vector.getValor(0), posicion = 0;
    bool seguir = true;

    while (seguir == true)
    {
        if ((2 * posicion) + 1 < vector.getN()) //Existe hijo izda?
        {
            if ((2 * posicion) + 2 < vector.getN()) //Existe hijo dcha?
            {
                if (vector.getValor((2 * posicion) + 1) <= vector.getValor((2 * posicion) + 2)) //Cuál de los dos tiene mayor valor?
                { 
                    if (valor > vector.getValor((2 * posicion) + 1))
                    {
                        vector.setValor(posicion, vector.getValor((2 * posicion) + 1));
                        posicion = (2 * posicion) + 1;
                        vector.setValor(posicion, valor);
                    }
                    else
                        seguir = false;
                }
                else
                {
                    if (valor > vector.getValor((2 * posicion) + 2))
                    {
                        vector.setValor(posicion, vector.getValor((2 * posicion) + 2));
                        posicion = (2 * posicion) + 2;
                        vector.setValor(posicion, valor);
                    }
                    else
                        seguir = false;
                }
            }
            else if (valor > vector.getValor((2 * posicion) + 1))
            {
                vector.setValor(posicion, vector.getValor((2 * posicion) + 1));
                posicion = (2 * posicion) + 1;
                vector.setValor(posicion, valor);
            }
            else
                seguir = false;
        }
        else
            seguir = false;
    }
}
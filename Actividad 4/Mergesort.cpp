#include <iostream>

using namespace std;

void combinar(int a[], int longA, int b[], int longB, int c[]);
void ordenarMergesort(int arr[], int longArr);

int main(){
    int n; cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n > 0) ordenarMergesort(arr, n);
}

void combinar(int a[], int longA, int b[], int longB, int c[]){
    int posA = 0, posB = 0;

    for(int i = 0; i < longA + longB; i++){
        if(posA == longA){
            c[i] = b[posB];
            posB++;
        } else if(posB == longB){
            c[i] = a[posA];
            posA++;
        } else if(a[posA] < b[posB]){
            c[i] = a[posA];
            posA++;
        } else{
            c[i] = b[posB];
            posB++;
        }
    }
}

void ordenarMergesort(int arr[], int longArr){
    int mitad = longArr / 2;

    if(longArr == 1)
        return;
    else{
        ordenarMergesort(arr, mitad);
        ordenarMergesort(arr + mitad, longArr - mitad);

        int *temp = new int[longArr];

        combinar(arr, mitad, arr + mitad, longArr - mitad, temp);
        
        for(int i = 0; i < longArr; i++){
            arr[i] = temp[i];
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

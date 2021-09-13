#include <iostream>

using namespace std;

void devolverCambio(int n);

int main() {
	int n;
	cin >> n;
	while (n > 0) {
		devolverCambio(n);
		cout << "\n";
		cin >> n;
	}
}

void devolverCambio(int n) {
	int arr[] = { 500, 200, 100, 50, 25, 10, 5, 1 }, res[8];

	for (int i = 0; i < 8; i++) {
		if (n >= arr[i]) {
			res[i] = n / arr[i];
			n = n - (arr[i] * (n / arr[i]));
		} else {
			res[i] = 0;
		}
		cout << res[i] << " ";
	}
}
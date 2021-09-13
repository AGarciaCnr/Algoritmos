#include <iostream>

using namespace std;

float raiz(float n, float error, float min, float max);

int main() {
	float n, error;
	cin >> n >> error;
	
	if (n > 0 && error > 0) {
		cout << raiz(n, error, 0, n);
	} else {
		cout << "ERROR";
	}
}

float raiz(float n, float error, float min, float max) {
	if (n - error <= ((min + max) / 2) * ((min + max) / 2) && ((min + max) / 2) * ((min + max) / 2) <= n + error) {
		return (min + max) / 2;
	} else {
		if (((min + max) / 2) * ((min + max) / 2) > n) {
			cout << (min + max) / 2 << "\n";
			return raiz(n, error, min, (min + max) / 2);
		} else {
			cout << (min + max) / 2 << "\n";
			return raiz(n, error, (min + max) / 2, max);
		}
	}
}
#include <iostream>
#include <string>

using namespace std;

bool pal(unsigned int n, string palabra);

int main() {
	string palabra;
	cin >> palabra;

	unsigned int n = palabra.length();

	cout << pal(n, palabra);

	return 0;
}

bool pal(unsigned int n, string palabra) {
	
	if (n == palabra.length() / 2) {
		return palabra[palabra.length() - n] == palabra[n - 1];
	}

	if (palabra[palabra.length() - n] == palabra[n - 1] && pal(n - 1, palabra) == 1) {
		return 1;
	} else {
		return 0;
	}
}

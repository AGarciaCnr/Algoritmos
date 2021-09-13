#include <iostream>

using namespace std;

int comb(int n, int r);
int fact(int n);

int main() {
	int n = 0, r = 0;
	cin >> n >> r;
	while (n >= 0) {
		if (n >= r && r >= 0) {
			cout << comb(n, r) << "\n";
		} else {
			cout << "ERROR\n";
		}
		cin >> n >> r;
	}
}

int comb(int n, int r) {
	return fact(n) / (fact(r) * fact(n - r));
}

int fact(int n) {
	if (n == 0) {
		return 1;
	}
	return n * fact(n - 1);
}
#include <iostream>

using namespace std;

void fact(int **arr);

int main() {
	int n, r;
	int** arr;
	arr = new int* [10];
	for (int i = 1; i < 11; i++) {
		arr[i - 1] = new int[i];
	}
	fact(arr);

	cin >> n >> r;
	while (n > 0) {
		if (n >= r && r >= 0) {
			cout << arr[n][r] << "\n";
		}
		else {
			cout << "ERROR\n";
		}
		cin >> n >> r;
	}
}

void fact(int **arr) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (i == 0 || j == 0 || i == j) {
				arr[i][j] = 1;
			} else {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
}
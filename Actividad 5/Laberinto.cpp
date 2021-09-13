#include <iostream>

using namespace std;

bool movimiento(char lab[10][10], int x, int y, int &xF, int &yF);

int main() {
	char lab[10][10];
	int x = 0, y = 0, xF = 0, yF = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> lab[i][j];
		}	
	}

	if (movimiento(lab, x, y, xF, yF) == 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << lab[i][j];
			}
			cout << "\n";
		}
		cout << "ENCONTRADO " << xF << " " << yF << "\n";
	} else {
		cout << "INALCANZABLE" << "\n";
	}
}

bool movimiento(char lab[10][10], int x, int y, int &xF, int &yF) {
	if (x < 10 && x >= 0 && y < 10 && y >= 0 ) {
		if (lab[x][y] == '.') {
			lab[x][y] = 'X';
			if (movimiento(lab, x - 1, y, xF, yF)) {
				return true;
			}
			if (movimiento(lab, x, y + 1, xF, yF)) {
				return true;
			}
			if (movimiento(lab, x + 1, y, xF, yF)) {
				return true;
			}
			if (movimiento(lab, x, y - 1, xF, yF)) {
				return true;
			}
			lab[x][y] = '.';
			return false;
		} else if (lab[x][y] == 'T'){
			xF = x;
			yF = y;
			return true;
		}
	}
	return false;
}
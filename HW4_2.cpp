//Вводятся размеры двумерного массива и его элементы. Вывести сумму положительных элементов массива

#include <iostream>
using namespace std;

void input(int** a, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
}

int Sum(int** a, int m, int n) {
	int sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] > 0) sum += a[i][j];
		}
	}
	return sum;
}

void output(int** a, int m, int n) {
	cout << "Array:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int m, n;
	cout << "Enter (m, n) :";
	cin >> m >> n;
	int** a = new int* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[n];
	}
	input(a, m, n);
	output(a, m, n);
	cout << "Sum of the positive elements of an array = " << Sum(a, m, n);
	for (int i = 0; i < m; i++) {
		delete[]a[i];
	}
	delete[]a;
}
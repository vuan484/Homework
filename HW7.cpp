#include <iostream>
#include <vector>
using namespace std;

//HW7
struct fraction {
	int a;
	int b;
	int GCD(const int &a, const int &b) {
		if (a == 0) return a;
		if (b == 0) return b;
		if (a == b) return a;
		if (a > b) return GCD(a - b, b);
		return GCD(a, b - a);
	}
	
};

void reduction(fraction& x) {
	cout << (x.a / x.GCD(x.a,x.b)) << "/" << (x.b / x.GCD(x.a,x.b));
}
void input(int* a, int& n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void output(int* a, int& n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void sort(int* a, int& n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) swap(a[i], a[j]);
		}
	}
}
int main() {
	int n;
	cout << "Enter n:" << endl;
	cin >> n;
	int* a = new int[n];
	cout << "Enter Array:" << endl;
	input(a, n);
	sort(a, n);
	cout << "Sorted Array:" << endl;
	output(a, n);
	delete[]a;
	//
	fraction x;
	cout << "\nEnter numerator & denominator :" << endl;
	cin >> x.a >> x.b;
	cout << "Fraction reduction :";
	reduction(x);
}
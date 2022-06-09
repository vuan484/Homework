#include <iostream>
#include <vector>
using namespace std;
int main()
{}
void inchtocen(float &x) {
	cout << "Length from inches to centimeters: " << x * 2.54;
}

void retangulararea(float &a, float &b) {
	cout << "Area = " << a * b;
}

void reverse(int& n) {
	int temp;
	int res = 0;
	int main ()
	{
	while (n > 0){
		temp = n % 10;
		res += res * 10 + temp;
		n /= 10;
	}
	cout << "Reverse = " << res;
	}
}

void positivenumber() {
	vector<int> vec;
	int number;
	bool check = true;
	do {
		cout << "Enter number:"; cin >> number;
		vec.push_back(number);
	} while (number != 0);
	for (int x : vec) {
		if (x < 0) check = false;
	}
	if (check == true) cout << "All elements are positive";
	else cout << "All elements are not positive";
}
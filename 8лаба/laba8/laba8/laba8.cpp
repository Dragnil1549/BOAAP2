#include <iostream>
using namespace std;

int x;
double y = 0;

void funct(unsigned n) {
	if (n - 1)
		funct(n - 1);
	y += cos(n * x);
}

void main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите n" << endl;
	cin >> n;
	cout << "Введите x" << endl;
	cin >> x;
	funct(n);
	cout << y;
}
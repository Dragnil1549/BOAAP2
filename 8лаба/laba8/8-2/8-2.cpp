#include <iostream>
using namespace std;

int task10(int, int);

void main() {
	setlocale(LC_ALL, "Russian");
	int a;
	int b;
	cin >> a;
	cin >> b;
	cout << task10(a, b) << endl;
}

int task10(int m, int n) {
	return (m == 0 || n == 0) ? n + 1 : task10(m - 1, task10(m, n - 1));
}

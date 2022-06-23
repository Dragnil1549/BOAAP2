#include <iostream>
#include <ctime> 
using namespace std;

void dop2(int* l, int* r) {
	int sz = r - l;
	if (sz <= 1) return;
	bool b = true;
	int* beg = l - 1;
	int* end = r - 1;
	while (b) {
		b = false;
		beg++;
		for (int* i = beg; i < end; i++) {
			if (*i > *(i + 1)) {
				swap(*i, *(i + 1));
				b = true;
			}
		}
		if (!b) break;
		end--;
		for (int* i = end; i > beg; i--) {
			if (*i < *(i - 1)) {
				swap(*i, *(i - 1));
				b = true;
			}
		}
	}
}
void dop3() {
	srand(static_cast<unsigned int>(time(0)));
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = rand();
		cout << a[i] << ' ';
	}
	cout << endl;
	int i, j, t;
	for (i = 1; i < 4; i++)
		for (j = 4 - 1; j >= i; j--)
			if (a[j - 1] > a[j]) {
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
	for (i = 7; i < 10; i++)
		for (j = 10 - 1; j >= i; j--)
			if (a[j - 1] < a[j]) {
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}
}
void dop4() {
	srand(static_cast<unsigned int>(time(0)));
	int a[15];
	for (int i = 0; i < 15; i++) {
		a[i] = rand() % 11 - 5;
		cout << a[i] << ' ';
	}
	cout << endl;
	int i, j, t;
	for (i = 1; i < 15; i++)
		for (j = 15 - 1; j >= i; j--)
			if (a[j - 1] > a[j]) {
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}

	int count = 15;

	for (i = 0; i < 15; i++)
		cout << a[i] << ' ';
	cout << endl;

	for (i = 0; i < count; i++)
		if (a[i] == a[i + 1]) {
			count--;
			for (j = i; j < count; j++)
				a[j] = a[j + 1];
			i--;
		}

	for (int i = 0; i < count + 1; i++) {
		cout << a[i] << ' ';
	}
}

void main() {
	setlocale(LC_ALL, "Russian");
	int choise;
	cin >> choise;
	switch (choise)
	{
	case 1: cout << "доп наелся и спит" << endl; break;
	case 2: dop2(); break;
	case 3: dop3(); break;
	case 4: dop4(); break;
	}
}
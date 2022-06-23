#include <iostream>
#include <ctime> 
using namespace std;

int getHoarBorder(int* A, int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] > brd);
		while (A[++i] < brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}

double sortHoar(int* A, int sm, int em)
{
	double start_time = clock();
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		sortHoar(A, sm, hb);
		sortHoar(A, hb + 1, em);
	}
	double end_time = clock();
	double search_time = end_time - start_time;
	return search_time / 1000.0;
}


double bubble(int* arr, int nu) {
	double start_time = clock();
	int i, j, t;
	for (i = 1; i < nu; i++)
		for (j = nu - 1; j >= i; j--)
			if (arr[j - 1] > arr[j]) {
				t = arr[j - 1];
				arr[j - 1] = arr[j]; arr[j] = t;
			}
	double end_time = clock();
	double search_time = end_time - start_time;
	return search_time / 1000.0;
}

double shell(int* arr, int nu) {
	double start_time = clock();
	int step, i, j, tmp;
	for (step = nu / 2; step > 0; step /= 2)
		for (i = step; i < nu; i++)
			for (j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step) {
				tmp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = tmp;
			}
	double end_time = clock();
	double search_time = end_time - start_time;
	return search_time / 1000.0;
}

double insert(int* arr, int nu) {
	double start_time = clock();
	int t, i, j;
	for (i = 1; i < nu; i++) {
		t = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > t; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = t;
	}
	double end_time = clock();
	double search_time = end_time - start_time;
	return search_time / 1000.0;
}

double selection(int* arr, int nu) {
	double start_time = clock();
	int k, i, j;
	for (i = 0; i < nu - 1; i++) {
		for (j = i + 1, k = i; j < nu; j++)
			if (arr[j] < arr[k])
				k = j;
		int c = arr[k]; arr[k] = arr[i];
		arr[i] = c;
	}
	double end_time = clock();
	double search_time = end_time - start_time;
	return search_time / 1000.0;

}

void var12() {
	srand(static_cast<unsigned int>(time(0)));
	int num;
	cin >> num;
	int n = (num + 1) / 2;
	int* a = new int[num];
	for (int i = 0; i < num; i++) {
		a[i] = rand();
	}

	int* b = new int[n];
	for (int i = 0; i < n; i++)
		b[i] = a[i * 2];


	cout << bubble(b, n) << endl;

	for (int i = 0; i < n; i++)
		b[i] = a[i * 2];

	cout << selection(b, n) << endl;



	delete[] a;
	delete[] b;
}

void var10() {

	srand(static_cast<unsigned int>(time(0)));
	int num;
	cin >> num;
	int* a = new int[num];
	for (int i = 0; i < num; i++) {
		a[i] = rand();
	}

	srand(static_cast<unsigned int>(time(0)));
	int* b = new int[num];
	for (int i = 0; i < num; i++) {
		b[i] = rand() % 5000;
	}

	int max = b[0];
	for (int i = 1; i < num; i++) {
		if (max < b[i])
			max = b[i];
	}
	int count = 0;
	for (int i = 0; i < num; i++) {
		if (max < a[i])
			count++;
	}
	int* c = new int[count];
	int j = 0;
	for (int i = 0; i < num; i++) {
		if (max < a[i]) {
			c[j] = a[i];
			j++;
		}
	}
	cout << bubble(c, count) << endl;

	j = 0;
	for (int i = 0; i < num; i++) {
		if (max < a[i]) {
			c[j] = a[i];
			j++;
		}
	}

	cout << insert(c, count) << endl;

	delete[] a;
	delete[] b;
	delete[] c;
}

void var14() {
	srand(static_cast<unsigned int>(time(0)));
	int num;
	cin >> num;
	int* a = new int[num];
	for (int i = 0; i < num; i++) {
		a[i] = rand();
	}
	srand(static_cast<unsigned int>(time(0)));
	int* b = new int[num];
	for (int i = 0; i < num; i++) {
		b[i] = rand();
	}
	int* c = new int[num];
	for (int i = 0; i < num; i++) {
		if (i % 2)
			c[i] = b[i];
		else
			c[i] = a[i];
	}
	
	cout << "пузырь" << bubble(c, num) << endl;

	for (int i = 0; i < num; i++) {
		if (i % 2)
			c[i] = b[i];
		else
			c[i] = a[i];
	}


	cout << "shell" << shell(c, num) << endl;

	delete[] a;
	delete[] b;
	delete[] c;
}
void var16() {

	srand(static_cast<unsigned int>(time(0)));
	int num;
	cin >> num;
	int* a = new int[num];
	for (int i = 0; i < num; i++) {
		a[i] = rand();
	}

	int min = a[0];
	int minpos;
	for (int i = 1; i < num; i++) {
		if (min > a[i]) {
			min = a[i];
			minpos = i;
		}
	}
	int n = (num - minpos) / 2;
	int* b = new int[n];
	for (int i = 0; i < n; i++)
		b[i] = a[i * 2 + minpos];

	cout << shell(b, n) << endl;

	for (int i = 0; i < n; i++)
		b[i] = a[i * 2 + minpos];

	cout << sortHoar(b, 0, n - 1) << endl;

	delete[] a;
	delete[] b;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int choise;
	cout << "1 - вариант 10\n2 - вариант 12\n3 - вариант 14\n4 - вариант 16\n";
	cin >> choise;
	switch (choise) {
	case 1: var10(); break;
	case 2: var12(); break;
	case 3: var14(); break;
	case 4: var16(); break;
	}
}
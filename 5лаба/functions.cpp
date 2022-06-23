#include "Header.h"

stack* myStack = nullptr;

void message() {
	cout << endl;
	cout << "Что будем делать?" << endl;
	cout << "1 - добавить элементы в стек" << endl;
	cout << "2 - добавить данные из файла" << endl;
	cout << "3 - показать все" << endl;
	cout << "4 - записать данные в файл" << endl;
	cout << "5 - определить, есть ли в стеке хотя бы один элемент, лежащий в заданном диапазоне" << endl;
	cout << "6 - очистить стек" << endl;
	cout << "7 - изъять элемент из стека" << endl;
	cout << "8 - распределить элементы по двум стекам" << endl;
	cout << "Введите 0, чтобы выйти" << endl;
}

int getInt() { //вспомогательная. проверяет введенное значение, возвращает 0, если некорректное
	int a;
	cin >> a;
	if (cin.fail()) { // если извлечение оказалось неудачным,
		cin.clear(); // то возвращаем cin в 'обычный' режим работы
		cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
		return NULL;
	}
	else {
		return a;
	}
}

void push(int temp) { //помещает значение в стек
	stack* buff;
	buff = new stack();
	buff->data = temp;
	buff->next = myStack;
	myStack = buff;
}

void pushCon() { //помещает значения в стек, пока значения корректны
	bool input = true;
	int temp;

	cout << "Вводите числа, чтобы добавить их в стек. Введите 0, чтобы прекратить ввод ";
	do {
		temp = getInt();
		if (temp) {
			push(temp);
		}
	} while (temp);
}

void pushFile() { //дописывает в стек значения из файла
	ifstream ifile("task6.txt");
	int temp;
	while (ifile >> temp) {
		push(temp);
	}
}

void showAll() { //вывод всех значений
	stack* buff;
	buff = myStack;
	while (buff) {
		cout << buff->data << " << ";
		buff = buff->next;
	}
	cout << endl;
}

void write() { // записать стек в файл
	ofstream ofile("task6.txt");
	stack* buff;

	while (myStack) {
		buff = myStack;
		ofile << buff->data << " ";
		myStack = buff->next;
		delete buff;
	}
}

void clean() { // очистить стек
	stack* buff;
	while (myStack) {
		buff = myStack;
		myStack = buff->next;
		delete buff;
	}
}

int pop() { //извлечь из стека
	if (!myStack) {
		cout << "Стек пуст" << endl;
		return NULL;
	}
	stack* buff;
	int temp;

	buff = myStack;
	temp = buff->data;
	myStack = buff->next;

	delete buff;
	return temp;
}

int check() { //определяет, есть ли в стеке хотя бы один элемент, лежащий в заданном диапазоне 
	int top;
	int bottom;
	stack* buff = myStack;

	cout << "Введите нижнюю границу: ";
	bottom = getInt();
	cout << "Введите верхнюю границу: ";
	top = getInt();

	if (top < bottom) {
		cout << "Некорректные значения" << endl;
		return -1;
	}

	while (buff) {
		if (buff->data >= bottom && buff->data <= top) {
			cout << "Значение в указанном диапазоне есть" << endl;
			return 0;
		}
		buff = buff->next;
	}
	cout << "Значений в указанном диапазоне нет" << endl;
	return 0;
}

void st() { //разделение на два стека и их вывод
	stack* buff = myStack;
	int temp; int i = 0;
	stack* buff1;
	stack* buff2;
	stack* k1 = nullptr;
	stack* k2 = nullptr;
	if (!myStack) {
		cout << "Стек пуст" << endl;
		exit(1);
	}

	while (buff) {
		temp = buff->data;
		if (i % 2 == 0) {
			buff1 = new stack();
			buff1->data = temp;
			buff1->next = k1;
			k1 = buff1;
		}
		else {
			buff2 = new stack();
			buff2->data = temp;
			buff2->next = k2;
			k2 = buff2;
		}
		buff = buff->next;
		i++;
	}
	while (k1) {
		cout << k1->data << " << ";
		buff1 = k1;
		k1 = k1->next;
		delete buff1;
	}
	cout << endl;
	while (k2) {
		cout << k2->data << " << ";
		buff2 = k2;
		k2 = k2->next;
		delete buff2;
	}
}
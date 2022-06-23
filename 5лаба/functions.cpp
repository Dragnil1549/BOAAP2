#include "Header.h"

stack* myStack = nullptr;

void message() {
	cout << endl;
	cout << "��� ����� ������?" << endl;
	cout << "1 - �������� �������� � ����" << endl;
	cout << "2 - �������� ������ �� �����" << endl;
	cout << "3 - �������� ���" << endl;
	cout << "4 - �������� ������ � ����" << endl;
	cout << "5 - ����������, ���� �� � ����� ���� �� ���� �������, ������� � �������� ���������" << endl;
	cout << "6 - �������� ����" << endl;
	cout << "7 - ������ ������� �� �����" << endl;
	cout << "8 - ������������ �������� �� ���� ������" << endl;
	cout << "������� 0, ����� �����" << endl;
}

int getInt() { //���������������. ��������� ��������� ��������, ���������� 0, ���� ������������
	int a;
	cin >> a;
	if (cin.fail()) { // ���� ���������� ��������� ���������,
		cin.clear(); // �� ���������� cin � '�������' ����� ������
		cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
		return NULL;
	}
	else {
		return a;
	}
}

void push(int temp) { //�������� �������� � ����
	stack* buff;
	buff = new stack();
	buff->data = temp;
	buff->next = myStack;
	myStack = buff;
}

void pushCon() { //�������� �������� � ����, ���� �������� ���������
	bool input = true;
	int temp;

	cout << "������� �����, ����� �������� �� � ����. ������� 0, ����� ���������� ���� ";
	do {
		temp = getInt();
		if (temp) {
			push(temp);
		}
	} while (temp);
}

void pushFile() { //���������� � ���� �������� �� �����
	ifstream ifile("task6.txt");
	int temp;
	while (ifile >> temp) {
		push(temp);
	}
}

void showAll() { //����� ���� ��������
	stack* buff;
	buff = myStack;
	while (buff) {
		cout << buff->data << " << ";
		buff = buff->next;
	}
	cout << endl;
}

void write() { // �������� ���� � ����
	ofstream ofile("task6.txt");
	stack* buff;

	while (myStack) {
		buff = myStack;
		ofile << buff->data << " ";
		myStack = buff->next;
		delete buff;
	}
}

void clean() { // �������� ����
	stack* buff;
	while (myStack) {
		buff = myStack;
		myStack = buff->next;
		delete buff;
	}
}

int pop() { //������� �� �����
	if (!myStack) {
		cout << "���� ����" << endl;
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

int check() { //����������, ���� �� � ����� ���� �� ���� �������, ������� � �������� ��������� 
	int top;
	int bottom;
	stack* buff = myStack;

	cout << "������� ������ �������: ";
	bottom = getInt();
	cout << "������� ������� �������: ";
	top = getInt();

	if (top < bottom) {
		cout << "������������ ��������" << endl;
		return -1;
	}

	while (buff) {
		if (buff->data >= bottom && buff->data <= top) {
			cout << "�������� � ��������� ��������� ����" << endl;
			return 0;
		}
		buff = buff->next;
	}
	cout << "�������� � ��������� ��������� ���" << endl;
	return 0;
}

void st() { //���������� �� ��� ����� � �� �����
	stack* buff = myStack;
	int temp; int i = 0;
	stack* buff1;
	stack* buff2;
	stack* k1 = nullptr;
	stack* k2 = nullptr;
	if (!myStack) {
		cout << "���� ����" << endl;
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
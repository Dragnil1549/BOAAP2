#include <iostream>
#include <iomanip>
using namespace std;
#define LEN 16

struct date {
	unsigned year : 11; //не может быть больше нынешней даты, знак хранить не нужно, значит, 11 битов (2048)
	unsigned mounth : 4; //макимум 12, знак хранить не нужно, значит, 4 бита
	unsigned day : 5; // максимум 31, знак хранить не нужно, значит, нужно 5 битов
};


struct sitizen {
	char name[LEN];
	char surname[LEN];
	char adress[LEN];
	char phone[LEN];
	char place[LEN];
	date birthday;
};

void showMessage(); // вывести сообщение из меню
void inputDate(date* dat); //вспомогательная, ввод даты
void showDate(date* dat); //вспомогательная, вывод даты
int inputSitizen(int size); //ввести одну запись
int showSitizen(int index); //вывести одну запись
int showAll(int size); //вывести все записи
int findSitizen(); //найти запись по году рождения

//задаем переменные для работы программы
sitizen* list; // указатель на динамический массив, с которым будем работать
static int current = 0; //переменная отсчитывает количество сделанных записей

void main() {
	setlocale(LC_ALL, "Russian");
	int size;
	int choise;
	int choise1;

	cout << "Сколько будет записей?" << endl;
	cin >> size;
	list = new sitizen[size];

	do {
		showMessage();
		cin >> choise;
		switch (choise) {
		case 1: inputSitizen(size); break;
		case 2: showAll(size); break;
		case 3: cin >> choise1;  showSitizen(choise1 - 1); break;
		case 4: findSitizen(); break;
		default: choise = 6; break;
		}
	} while (choise != 6);

	delete[] list;
}

void showMessage() {
	cout << endl << "Что будем делать?" << endl;
	cout << "1 - ввести с клавиатуры" << endl;
	cout << "2 - вывести на экран все" << endl;
	cout << "3 - вывести на экран запись определенного номера (введите номер записи)" << endl;
	cout << "4 - найти человека по фамилии" << endl;
	cout << "Нажмите любую клавишу, чтобы выйти" << endl;
}


void inputDate(date* dat) {
	int input;

	cout << "Год рождения: (не больше 2048)" << endl;
	cin >> input;
	input = (int)abs(input);
	dat->year = (input > 0 && input < 2048) ? input : 0;

	cout << "Месяц: " << endl;
	cin >> input;
	input = (int)abs(input);
	dat->mounth = (input > 0 && input < 13) ? input : 0;

	cout << "День: " << endl;
	cin >> input;
	input = (int)abs(input);
	dat->day = (input > 0 && input < 32) ? input : 0;
}

void showDate(date* dat) {
	cout << dat->day << "." << dat->mounth << "." << dat->year << endl;
}

int inputSitizen(int size) {
	if (current >= size) {
		cout << "Нельзя создать запись: список переполнен" << endl;
		return -1;
	}

	cout << "Имя:" << endl;
	cin >> list[current].name;
	cout << "Фамилия:" << endl;
	cin >> list[current].surname;
	cout << "Адрес:" << endl;
	cin >> list[current].adress;
	cout << "Телефон:" << endl;
	cin >> list[current].phone;
	cout << "Место работы:" << endl;
	cin >> list[current].place;
	cout << "Дата рождения: " << endl;
	inputDate(&(list[current].birthday));
	current++;
	cout << "Новая запись создана\n" << endl;
	return 0;
}

int showSitizen(int index) { //вспомогательная функция, выводит на экран одну запись
	if (!(index >= 0 && index < current && current > 0)) {
		cout << "Ошибка!" << endl;
		return -1;
	}

	cout << list[index].name << endl;
	cout << list[index].surname << endl;
	cout << list[index].place << endl;
	cout << list[index].phone << endl;
	cout << list[index].adress << endl;
	showDate(&list[index].birthday);


	cout << endl;
	return 0;
}


int showAll(int size) {
	if (current == 0) {
		cout << "Список пуст" << endl;
		return -1;
	}
	for (int i = 0; i < current && i < size; i++) {
		showSitizen(i);
	}
	return 0;
}


int findSitizen() {
	if (current == 0) {
		cout << "Операция невозможна: список пуст " << endl;
		return -1;
	}

	char compare[LEN];
	cout << "Какую фамилию ищем?" << endl;
	cin >> compare;

	for (int i = 0; i < current; i++) {
		if (strcmp(list[i].surname, compare) == 0) {
			showSitizen(i);
		}
	}
	return 0;
}
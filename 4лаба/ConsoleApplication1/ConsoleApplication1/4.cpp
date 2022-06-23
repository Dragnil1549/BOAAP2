#include <iostream>
#include <fstream>
using namespace std;

struct list
{
	double number;
	list* next;
};

void insert(list*&, double); //функция добавления элемента, передается адрес спис-ка и символ, который добавляется 
double del(list*&, double); //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*); //функция, которая проверяет, пуст ли список 
void printList(list*); //функция вывода 
void menu(void); //функция, показывающая меню 
void zad(list*); //функция с заданием
void toFile(list*&); //Запись в файл 
void fromFile(list*&); //Считывание из файла

int main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = NULL;
	int choice;
	double value;
	menu(); // вывести меню 
	cout << " ? ";
	cin >> choice;
	while (choice != 6)
	{
		switch (choice)
		{
		case 1:
			cout << "Введите число "; // добавить число в список 
			cin >> value;
			insert(first, value);
			printList(first);
			break;
		case 2:
			if (!IsEmpty(first)) // удалить число из списка 
			{
				cout << "Введите удаляемое число ";
				cin >> value;
				if (del(first, value))
				{
					cout << "Удалено число " << value << endl;
					printList(first);
				}
				else cout << "Число не найдено" << endl;
			}
			else cout << "Список пуст" << endl;
			break;
		case 3:
			zad(first); // вычисление суммы
			break;
		case 4:
			toFile(first); //запись в файл
			break;
		case 5:
			fromFile(first); //вывод из файла
			break;
		default:
			cout << "Неправильный выбор" << endl;
			menu();
			break;
		}
		cout << "? ";
		cin >> choice;
	} cout << "Конец" << endl;
	return 0;
}

void menu(void) //Вывод меню 
{
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод числа" << endl;
	cout << " 2 - Удаление числа" << endl;
	cout << " 3 - задание" << endl;
	cout << " 4 - запись в файл" << endl;
	cout << " 5 - вывод из файла" << endl;
	cout << " 6 - Выход" << endl;
}

void insert(list*& p, double value) //Добавление числа value в список 
{
	list* newP = new list;
	if (newP != NULL) //есть ли место?
	{
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else cout << "Операция добавления не выполнена" << endl;
}

double del(list*& p, double value) // Удаление числа 
{
	list* previous, * current, * temp; if (value == p->number)
	{
		temp = p;
		p = p->next; // отсоединить узел 
		delete temp; //освободить отсоединенный узел 
		return value;
	}
	else
	{
		previous = p; current = p->next;
		while (current != NULL && current->number != value)
		{
			previous = current; current = current->next; // перейти к следующему 
		}
		if (current != NULL)
		{
			temp = current; previous->next = current->next; free(temp); return value;
		}
	}
	return 0;
}

int IsEmpty(list* p) //Список пустой? (1-да, 0-нет) 
{
	return p == NULL;
}

void printList(list* p) //Вывод списка 
{
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->number; p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void toFile(list*& p) //запись в файл
{
	list* temp = p;
	list buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf,
			sizeof(list));
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл mList.dat\n";
}

void fromFile(list*& p) //Считывание из файла 
{
	list buf, * first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read((char*)&buf, sizeof(list));
	while (!frm.eof())
	{
		insert(first, buf.number);
		cout << "-->" << buf.number;
		frm.read((char*)&buf, sizeof(list));
	}
	cout << "-->NULL" << endl;
	frm.close();
	p = first;
	cout << "\nСписок считан из файла mList.dat\n";
}

//основа
void zad(list* p) // Подсчет среднего значения положительных чисел 
{
	double sm = 0;
	int n = 0;
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		while (p != NULL)
		{
			if (p->number > 0) {
				n++;
				sm = sm + (p->number);
			}
			p = p->next;
		}
		cout << "Среднее значение положительных чисел = " << sm / n << endl;
	}
}

#include <iostream> 
using namespace std;
struct Character
{
	char info;
	Character* next;
};
int choise;

void menu();
void create(Character** begin, Character** end, char p); //формирование элементов очереди
void view(Character* begin); //функция вывода элементов очереди
void del(Character** begin); //удаление эдементов очереди
void siz(Character* begin); //подсчёт количестваэлементов в очереди

int main() {
	Character* begin = NULL, * end, * t;
	t = new Character;
	int size;
	char p;
	cout << "\nEnter size of queue=";
	cin >> size;
	cout << "Enter character= ";
	cin >> p;
	char f = p;
	t->info = p; //первый элемент
	t->next = NULL;
	begin = end = t;
	for (int i = 1; i < size; i++) //создание очереди 
	{
		cout << "Enter character= ";
		cin >> p;
		if (p == f) {
			view(begin);
			siz(begin);
			break;
		}
		create(&begin, &end, p);
	}
	do {
		menu();
		cin >> choise;
		switch (choise) {
		case 1:
		{
			view(begin);
			break;
		}
		case 2:
		{
			del(&begin);
			break;
		}
		case 3:
		{
			siz(begin);
		}
		}
	} while (choise != 0);
}

void menu() {
	cout << "1 - output of queue" << endl;
	cout << "2 - delete elements of queue" << endl;
	cout << "3 - number of elements in queue" << endl;
}

void create(Character** begin, Character** end, char p) //Формирование элементов очереди 
{
	Character* t = new Character;
	t->next = NULL;
	if (*begin == NULL)
		*begin = *end = t;
	else
	{
		t->info = p;
		(*end)->next = t;
		*end = t;
	}
}

void view(Character* begin) //Вывод элементов очереди 
{
	Character* t = begin;
	if (t == NULL) {
		cout << "Character is empty\n";
		return;
	}
	else
		while (t != NULL)
		{
			cout << t->info << endl;
			t = t->next;
		}
}
void del(Character** begin) //удаление жлементов очереди
{
	int n;
	Character* t;
	t = new Character;
	cout << "How many elements do you want to delete?" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		t = *begin;
		*begin = (*begin)->next;
		delete t;
	}

}

void siz(Character* begin) // подсчёт элементов очереди 
{
	Character* t = begin;
	int n = 0;
	if (t == NULL) {
		cout << "Character is empty\n";
		return;
	}
	else
	{
		while (t != NULL)
		{
			n++;
			t = t->next;
		}
		cout << "size of queue is " << n << endl;
	}
}
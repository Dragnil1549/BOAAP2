#include <iostream>
#include <fstream>
using namespace std;

struct stack {
	int data;
	stack* next;
};

void st(); //cоздание двух новых стеков

int pop(); //извлечение элемента

void message(); //меню

int getInt(); // вспомогательная. проверяет введенное значение, возвращает 0, если некорректное

void push(int); // вспомогательная. помещает одно значение в стек
void pushCon(); // ввод данных из консоли
void pushFile(); // ввод данных из файла 

void showAll(); // вывести на экран
void write(); // вывести в файл

int check(); //определяет, есть ли в стеке хотя бы один элемент, лежащий в заданном диапазоне

void clean(); //удаляет все значения из стека
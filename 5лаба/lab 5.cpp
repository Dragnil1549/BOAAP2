#include "Header.h"
//Разработать функцию, которая определяет, есть ли в стеке хотя бы один элемент, лежащий в заданном диапазоне.
//Разработать функцию, которая по одному стеку Stack строит 2 новых: Stack1 из четных элементов, Stack2 из нечетных


int main() {
	setlocale(LC_ALL, "Russian");
	int choice;

	do {
		message();

		choice = getInt();

		switch (choice) {
		case 1: pushCon(); break;
		case 2: pushFile(); break;
		case 3: showAll(); break;
		case 4: write(); break;
		case 5: check(); break;
		case 6: clean(); break;
		case 7: pop(); break;
		case 8: st(); break;
		default: choice = 0; break;
		}

	} while (choice);

	clean();
	return 0;
}
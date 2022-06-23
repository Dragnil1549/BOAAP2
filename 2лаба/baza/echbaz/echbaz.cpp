#include <iostream>  
#include <fstream>
# define str_len 100                               
# define size 100
using namespace std;
void enter_new();
void del();
void change();
void out();
void search();
struct SpravochnikAbityrienta
{
	char vyz[str_len];
	char adres[str_len];
	char specialnoct[str_len];
	char stoimost[str_len];
	char konkyrs[str_len];
};
struct SpravochnikAbityrienta list_of_student[size];
struct SpravochnikAbityrienta bad;
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для изменения записи" << endl;
	cout << "4-для вывода записи(ей)" << endl;
	cout << "5-для поиска информации" << endl;
	cout << "6-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  change();  break;
		case 4:  out();	break;
		case 5:  search(); break;
		}
	} while (choice != 6);
}
void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		ofstream fout("spec.txt");
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Наименования вуза " << endl;
		cin >> list_of_student[current_size].vyz;
		cout << "Адрес " << endl;
		cin >> list_of_student[current_size].adres;
		cout << "Специальность " << endl;
		cin >> list_of_student[current_size].specialnoct;
		cout << "Конкурс " << endl;
		cin >> list_of_student[current_size].konkyrs;
		cout << "стоимость в $ " << endl;
		cin >> list_of_student[current_size].stoimost;
		current_size++;

	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_student[de1] = list_of_student[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			list_of_student[i] = bad;
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void change()
{
	int n, per;
	cout << "\nВведите номер строки" << endl; 	cin >> n;
	do
	{
		cout << "Введите: " << endl;
		cout << "1-для изменения вуза" << endl;
		cout << "2-для изменения адреса" << endl;
		cout << "3-для специальности" << endl;
		cout << "4-для конкурса" << endl;
		cout << "5-для стоимости" << endl;
		cout << "6-конец\n";
		cin >> per;
		switch (per)
		{
		case 1: cout << "Другой вуз";
			cin >> list_of_student[n - 1].vyz;   break;
		case 2: cout << "другой адрес";
			cin >> list_of_student[n - 1].adres; break;
		case 3: cout << "другая специальность ";
			cin >> list_of_student[n - 1].specialnoct; break;
		case 4: cout << "другой конкурс ";
			cin >> list_of_student[n - 1].konkyrs; break;
		case 5: cout << "другая стоисоть ";
			cin >> list_of_student[n - 1].stoimost; break;
		}
	} while (per != 6);
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void search()
{

}
void out()
{
	int sw, n;
	cout << "1-вывод строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << "Вуз ";
		cout << list_of_student[n - 1].vyz << endl;
		cout << "Адрес ";
		cout << list_of_student[n - 1].adres << endl;
		cout << "Спецеальность ";
		cout << list_of_student[n - 1].specialnoct << endl;
		cout << "Конкурс ";
		cout << list_of_student[n - 1].konkyrs << endl;
		cout << "Стоимость в $ ";
		cout << list_of_student[n - 1].stoimost << endl;
	}
	if (sw == 2)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << "Вуз ";
		cout << list_of_student[n - 1].vyz << endl;
		cout << "Адрес ";
		cout << list_of_student[n - 1].adres << endl;
		cout << "Спецеальность ";
		cout << list_of_student[n - 1].specialnoct << endl;
		cout << "Конкурс ";
		cout << list_of_student[n - 1].konkyrs << endl;
		cout << "Стоимость в $ ";
		cout << list_of_student[n - 1].stoimost << endl;
	}
	if (sw == 3)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
			cout << "Вуз ";
			cout << list_of_student[n - 1].vyz << endl;
			cout << "Адрес ";
			cout << list_of_student[n - 1].adres << endl;
			cout << "Специальность ";
			cout << list_of_student[n - 1].specialnoct << endl;
			cout << "Конкурс ";
			cout << list_of_student[n - 1].konkyrs << endl;
			cout << "Стоимость в $ ";
			cout << list_of_student[n - 1].stoimost << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}


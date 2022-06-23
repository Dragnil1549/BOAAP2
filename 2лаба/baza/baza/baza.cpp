#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;


//обьявление структуры
int const col = 5;
struct vuz
{
    char name[40];
    char regis[40];
    char genre[40];
    int rate;
    int price;
}film[col];

//прототипы ф-ций
void AddInfo();
void Searchname(char* name);
void Searchgenre(char* genre);
void Searchregis(char* regis);
void Searchpop(char* popgenre);
void ShowAll();

//главная программа
void main()
{
    char name[20], genre[20], regis[20], popgenre[20], choice;
    setlocale(LC_ALL, "rus");
    //меню
    do {
        cout << "Выберите требуемое действие:\n1-Добавить информацию о вузе...\n2-Поиск вуза по названию...\n";
        cout << "3-Поиск по специальности...\n4-Поиск по адресу...\n6-Показать все вузы...\n7-Выход...\n";
        cin >> choice;
        switch (choice) {
        case '1':
            AddInfo();
            break;
        case '2':
            cout << "Введите название вуза\n";
            cin >> name;
            Searchname(name);
            break;
        case '3':
            cout << "Введите специальность\n";
            cin >> genre;
            Searchgenre(genre);
            break;
        case '4':
            cout << "Введите адрес\n";
            cin >> regis;
            Searchregis(regis);
            break;
        case '6':
            ShowAll();
            break;
        case '7':
            exit(0);
            break;
        default:
            cout << "Неправильный выбор\n";
            break;
        }
    } while (choice != '7');
}

//ф-ция добавления информации
void AddInfo()
{
    int k;
    cout << "Введите кол-во записей:\n";
    cin >> k;
    for (int i = 0; i < k; i++) {
        cout << "Введите название вуза[" << i << "]:\n";
        cin >> film[i].name;
        cout << "Введите адрес[" << i << "]:\n";
        cin >> film[i].regis;
        cout << "Введите специльаность[" << i << "]:\n";
        cin >> film[i].genre;
        cout << "Введите конкурс[" << i << "]:\n";
        cin >> film[i].rate;
        cout << "Введите цену[" << i << "]:\n";
        cin >> film[i].price;
    }
}

//ф-ция поиска по названию
void Searchname(char* name)
{
    for (int i = 0; i < col; i++) {
        if (_stricmp(name, film[i].name) == 0) {
            cout << "Название вуза: " << film[i].name << "\n";
            cout << "Адрес: " << film[i].regis << "\n";
            cout << "Специальность: " << film[i].genre << "\n";
            cout << "конкурс: " << film[i].rate << "\n";
            cout << "Цена: " << film[i].price << "\n";
            cout << "##########################\n";
        }
        else
            cout << "не найден\n";
    }

}
//ф-ция поиска по жанру
void Searchgenre(char* genre)
{
    for (int i = 0; i < col; i++) {
        if (_stricmp(genre, film[i].genre) == 0) {
            cout << "Название вуза: " << film[i].name << "\n";
            cout << "Адрес: " << film[i].regis << "\n";
            cout << "Специальность: " << film[i].genre << "\n";
            cout << "Конкурс: " << film[i].rate << "\n";
            cout << "Цена: " << film[i].price << "\n";
            cout << "##########################\n";
        }
        else
            cout << " не найден\n";
    }

}

//ф-ция поиска по режиссеру
void Searchregis(char* regis)
{
    for (int i = 0; i < col; i++) {
        if (_stricmp(regis, film[i].regis) == 0) {
            cout << "Название вуза: " << film[i].name << "\n";
           cout << "Адрес: " << film[i].regis << "\n";
            cout << "специльаность: " << film[i].genre << "\n";
            cout << "Конкурс: " << film[i].rate << "\n";
            cout << "Цена: " << film[i].price << "\n";
            cout << "##########################\n";
        }
        else
            cout << " не найден\n";
    }

}



//ф-ция показа всех
void ShowAll()
{
    for (int i = 0; i < col; i++) {
        cout << "Название фильма: " << film[i].name << "\n";
        cout << "Режиссер фильма: " << film[i].regis << "\n";
        cout << "Жанр фильма: " << film[i].genre << "\n";
        cout << "Рейтинг фильма: " << film[i].rate << "\n";
        cout << "Цена диска с фильмом: " << film[i].price << "\n";
        cout << "##########################\n";
    }
}
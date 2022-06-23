
#include <iostream>
#include <cmath>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <string>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "    *******************************************" << "\n";
    cout << "    ***** БАЗА ДАННЫХ <<БАНКОВСКОЕ ДЕЛО>> *****" << "\n";
    cout << "    *******************************************                                                                                                                                                                        " << "\n";
    cout << "    Выберите один из вариантов:                " << "\n";
    cout << "     1 - Создание/дополнение базы данных" << "\n";
    cout << "     2 - Просмотр содержимого базы данных" << "\n";
    cout << "     3 - Поиск банков с максимальным годовым процентом" << "\n";
    cout << "     4 - Выход с программы" << "\n";
    cout << "     5 - Поиск по фамилии" << "\n";

    struct klieni;
    char lastname[256];
    char adres[256];
    int  summa;
    char a[20];
    int n;
    ofstream out("klienti.txt");
    out << "Номер Фамилия Адрес Сумма\n";

    cout << "Сколько нужно занести людей в базу данных?\n";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Введите фамилию человека\n";
        cin >> lastname;
        cout << "Введите адрес человека\n";
        cin >> adres;
        cout << "Введите суму вклада\n";
        cin >> summa;
        out << (i + 1) << " " << lastname << " " << adres << " " << summa << "\n";
    }

    out.close();

    ifstream in("klienti.txt");
    cout << "Введите фамилию человека для поиска\n";
    cin >> a;

    string str;
    bool is_found = false;
    while (getline(in, str))
    {
        if (str.find(a) != std::string::npos)
        {
            is_found = true;
            break;
        }
    }
    in.close();
    if (is_found)
    {
        cout << "Номер Фамилия Адрес Сумма\n";
        cout << str << "\n";
    }
    else
        cout << "Пользователя не найденно\n";

    //system("pause");
    return 0;
}
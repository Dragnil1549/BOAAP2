#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
int main()
{
    string s;
    int k, i;
    cout << "Please enter text:";
    getline(cin, s);
    char* str = new char[s.length()];
    strcpy(str, s.c_str());
    cout << "Vvedite k:";

    cin >> k;
    char* str1 = new char[k];
    char* str2 = new char[s.length() - k];

    int L = strlen(str);
    for (i = 0; i < k; i++) 
        str1[i] = str[i];
    str[i] != '\0';
    if (k < L)
        strcpy(str2, str + k); 
    cout << "Pervaya chast: " << str1 << endl << "Ostavsheyasa: " << str2 << endl;
    return 0;
}
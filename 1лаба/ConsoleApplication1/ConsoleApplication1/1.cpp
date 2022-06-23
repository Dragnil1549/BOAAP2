#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{   
    ifstream is("input.txt");
    ofstream os("output.txt");
    if (!is || !os) return 1;
    string str, word;
    unordered_set<string> uset;
    while (getline(is, str)) {
        uset.clear();
        stringstream ss(str);

        while (ss >> word) {
            if (!uset.insert(word).second) {
                os << str << '\n';
                break;
            }
        }
    }
    is.close();
    os.close();
    
    ifstream isss("input.txt");
    string str1;
    while (getline(isss, str1)) {
        string s, word, mostDig, mostLet;
        int i, count_letters, count_digits, max_letters = 0, max_digits = 0;
        stringstream words(str1);
        while (isss >> word) {
            i = 0;
            count_letters = 0;
            count_digits = 0;
            while (word[i])
            {
                if (word[i] >= '0' && word[i] <= '9') count_digits++;
                if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) count_letters++;
                i++;
            }
            if (count_digits > max_digits) { max_digits = count_digits; mostDig = word; }
            if (count_letters > max_letters) { max_letters = count_letters; mostLet = word; }
        }
        cout << "max: " << max_letters;
    }
    return 0;
}
#include <iostream>
#include <regex>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text = "This is the the text with repeated repeated words.";
    regex pattern(R"(\b(\w+)\s+\1\b)");

    if (regex_search(text, pattern)) {
        cout << "Знайдено повторювані слова:\n";

        for (sregex_iterator it(text.begin(), text.end(), pattern), end; it != end; ++it) {
            cout << (*it)[0] << endl;
        }
    }
    else {
        cout << "Повторюваних слів не знайдено.\n";
    }

    return 0;
}

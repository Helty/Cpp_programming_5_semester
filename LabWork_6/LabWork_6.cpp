#include <iostream>
#include <string>
#include <conio.h>
#include <regex>

//Вывести строку, если она имеет заданный формат:
// Числовой диапазон в формате (a-b),где a,b-положительные целые числа

using namespace std;

void OutputInformationAboutMe()
{
    cout << "Шестаков Андрей БИ-31 (21 вариант)" << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    const regex RegExp(R"(\(\d+\-\d+\))");

	do
	{
        system("cls");
        OutputInformationAboutMe();
        cout << "Введите строку соответствующую: Числовой диапазон в формате (a-b),где a,b-положительные целые числа." << endl << endl;
        string StringFromConsole;
        getline(cin, StringFromConsole);

        if (regex_search(StringFromConsole, RegExp))
        {
            cout << endl << endl << "Соответствие найдено!";
        }
        else
        {
            cout << endl << endl << "Соответствие не найдено!";
        }
        cout << endl << endl << "Для выхода нажмите ESC." << endl << endl;
    } while (_getch() != 27);
}

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <map>
#include <regex>
#include <set>

using namespace std;

/*1) Дана строка, состоящая из 5 слов через пробел, а также словарь для пар
слов и их синонимов. 
  2) Вывести набор синонимов для исходной строки в новую строку, исключая
повторяющиеся слова в случае их наличия. (Повторы + => исключаю)
  3) Исключить вывод слов не входящих в словарь. (Слова не из словаря - => исключать их)
  4) Вывести комментарии о том, встречалось ли слово ранее (Да/Нет), для
каждого слова в строке.
*/


void OutputInformationAboutMe()
{
    cout << "Шестаков Андрей БИ-31 (21 вариант)" << endl << endl;
}

void PrintStartData(string LineFiveWords, map<string, string> Dict)
{
    cout << "Ваши изначальные слова: " << LineFiveWords << endl;
    cout << "Ваш словарь: ";
    map <string, string> ::iterator it = Dict.begin();
    for (int i = 0; it != Dict.end(); it++)
    {
        cout << it->first << " : " << it->second << "; ";
    }
}


set <string> SetSynonymsForNewLine(string LineFiveWords, map<string, string> Dict)
{
    set <string> NewLineWord;
    regex WordsRegex("[^\\s]+");
    auto WordsBegin = sregex_iterator(LineFiveWords.begin(), LineFiveWords.end(), WordsRegex);
    auto WordsEnd = sregex_iterator();
    for (sregex_iterator i = WordsBegin; i != WordsEnd; ++i)
    {
        smatch Match = *i;
        string MatchWord = Match.str();
        if (Dict.find(MatchWord) != Dict.end())
        {
            NewLineWord.insert(Dict[MatchWord]);
        }
    }
    cout << endl << endl << "Не повторяющийся набор синонимов для первой строки: ";
    set <string> ::iterator it = NewLineWord.begin();
    for (int i = 1; it != NewLineWord.end(); i++, it++)
    {
        cout << *it << " ";
    }
    cout << ";"<< endl;
    return NewLineWord;
}

void PrintComment(string LineFiveWords)
{
    map <string, int> DictRepeat;
    regex WordsRegex("[^\\s]+");
    auto WordsBegin = sregex_iterator(LineFiveWords.begin(), LineFiveWords.end(), WordsRegex);
    auto WordsEnd = sregex_iterator();
    for (sregex_iterator i = WordsBegin; i != WordsEnd; ++i)
    {
        smatch Match = *i;
        string MatchWord = Match.str();

        if (DictRepeat.find(MatchWord) != DictRepeat.end())
        {
            DictRepeat[MatchWord] += 1;
        }
        else
        {
            DictRepeat.insert(make_pair(MatchWord, 1));
        }
    }
    map <string, int> ::iterator it = DictRepeat.begin();
    for (int i = 0; it != DictRepeat.end(); it++, i++)
    {
        if (it->second == 1)
        {
            cout << endl << "Слово " << it->first << " неповторимое в своём роде.";
        }
        else
        {
            cout << endl << "Слово " << it->first << " дублируется в списке.";
        }        
    }
}



int main()
{
    setlocale(LC_ALL, "Rus");
    OutputInformationAboutMe();

    do
    {
        string LineFiveWords = "Абсолютный Вариант Абсолютный Диалог Индустрия";
        map<string, string> Dict = { {"Абсолютный", "Совершенный"}, {"Диалог", "Беседа"}, {"Одежда", "Шмотки"} };

        PrintStartData(LineFiveWords, Dict);

        set <string> NewLineWord = SetSynonymsForNewLine(LineFiveWords, Dict);

        PrintComment(LineFiveWords);

        cout << endl << endl << "Для выхода нажмите ESC." << endl << endl;
    } while (_getch() != 27);


}

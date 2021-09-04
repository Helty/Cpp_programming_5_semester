#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

void OutputInformationAboutMe();
int GenerateSecretNumber();
void CheckCorrect(int SecretNumber, int Number);
bool UseSimpleHintOrNot();
void GetHint(int SecretNumber, int Number);

void OutputInformationAboutMe() { cout << "Шестаков Андрей БИ-31 (21 вариант)" << endl << endl; }
int GenerateSecretNumber() { return (rand() + rand()) % 10; }
void CheckCorrect(int SecretNumber, int Number) { if (SecretNumber == Number) cout << endl << endl << "Вы угадали!"; }

bool UseSimpleHintOrNot()
{
    cout << "Вы хотите использовать подсказки в игре-угадайке? \n(Введите 1 для подтверждения или любую другую цифру для отказа): ";
    if (_getch() == '1')
    {
        cout << endl << endl << "Подсказки включены!";
        return true;
    }
    else
    {
        cout << endl << endl << "Подсказки не включены!";
        return false;
    }
}
void GetHint(int SecretNumber, int Number)
{
    if (Number > SecretNumber) 
    { 
        cout << endl << endl << "Введеное число больше загаданного."; 
    }
    else 
    { 
        cout << endl << endl << "Введеное число меньше загаданного."; 
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    do
    {
        system("cls");
        int SecretNumber = GenerateSecretNumber();
        bool SimpleHint = UseSimpleHintOrNot();
        cout << endl << endl << "Игра началась! Число загадано.";
        int Number;
        while (true)
        {
            cout << endl << endl << "Введите число от (0 до 9): ";
            cin >> Number;
            if (SimpleHint)
            {
                if (SecretNumber == Number)
                {
                    cout << endl << endl << "Вы угадали!";
                    break;
                }
                else
                {
                    cout << endl << "Вы не угадали! Попробуйте ещё раз.";
                }
                GetHint(SecretNumber, Number);
            }
            else
            {
                if (SecretNumber == Number)
                {
                    cout << endl << endl << "Вы угадали!";
                    break;
                }
                else
                {
                    cout << endl << "Вы не угадали! Попробуйте ещё раз.";
                }
            }
        }
        cout << endl << endl << "Для выхода нажмите ESC" << endl << endl;
    } while (_getch() != 27);
}
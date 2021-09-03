#include <iostream>
#include <conio.h>

using namespace std;

void OutputInformationAboutMe();
int GetNumberOperand();
int OutputAndReturnSum(int);

void OutputInformationAboutMe()
{
    cout << "Шестаков БИ-31" << endl << endl;
}

int GetNumberOperand()
{
    int NumberOperands;
    do
    {
        cout << "Введите какое колличество операндов вы хотите использовать (максимально 4, минимум 1): ";
        cin >> NumberOperands;
    } while ((NumberOperands > 4) or (NumberOperands < 1));
    return NumberOperands;
}

int OutputAndReturnSum(int NumberOperands)
{
    int Counter = 0;
    int Sum = 0;
    for (int i = 0; i < NumberOperands; i++)
    {
        Counter = 0;
        cout << "Введите " << i + 1 << " операнд: ";
        cin >> Counter;
        Sum += Counter;
    }
    cout << endl << "Сумма ваших операндов: " << Sum << endl << endl;

    return Sum;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    OutputInformationAboutMe();

    do
    {
        int NumberOperands = GetNumberOperand();

        int Sum = OutputAndReturnSum(NumberOperands);

        cout << "MOD: " << Sum % 10 << endl << endl;
        cout << "Для выхода из программы нажмите Esc, для продолжения Enter." << endl << endl;
        cout << "-----------------------------------------------------------------------------------------------------" << endl;

    } while (_getch() != 27);

    return 0;
}


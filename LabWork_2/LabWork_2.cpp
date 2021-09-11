#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void OutputInformationAboutMe()
{
    cout << "Шестаков Андрей БИ-31 (21 вариант)" << endl << endl;
}

void PrintChessBoard(vector<vector<int>> Board, pair<int, int> Horse = {}, pair<int, int> Target = {})
{
    for (int line = 1; line < Board.size() + 1; line++)
    {
        for (int colum = 1; colum < Board.size() + 1; colum++)
        {
            if ((Horse.first == line) and (Horse.second == colum))
            {
                cout << " | " << "#";
            }
            else if ((Target.first == line) and (Target.second == colum))
            {
                cout << " | " << "1";
            }
            else
            {
                cout << " | " << Board[line - 1][colum - 1];
            }
        }
        cout << " |" << endl;
    }
}

pair<int, int> GetCoordinat()
{
    pair<int, int> Coordinats;
    int first = 0;
    int second = 0;
    do
    {
        cout << "Введите координату по вертикали(1-8): ";
        cin >> first;
        cout << "Введите координату по горизонтали(1-8): ";
        cin >> second;

    } while (((first + first) > 16) or 
             ((first + first) < 2) or
             ((second + second) > 16) or
             ((second + second) < 2));
    return {first, second};
}

bool CheckingError(vector<vector<int>> ChessBoard, pair<int, int> Horse, pair<int, int> Target)
{
    if (Horse == Target)
    {
        PrintChessBoard(ChessBoard, Horse, Target);
        cout << "Конь и место куда надо попасть совпадают!" << endl;
        return true;
    }
    else if (Target.first == Horse.first)
    {
        PrintChessBoard(ChessBoard, Horse, Target);
        cout << "Вы ходите конём который ходит буквой Г, значит он не сможет попасть на место находящееся на одной горизонтале с конём." << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void main()
{
    setlocale(LC_ALL, "Russian");

    OutputInformationAboutMe();

    vector<vector<int>> ChessBoard = { {0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0} };

    PrintChessBoard(ChessBoard);

    cout << endl << "Введите координаты коня (решётка): " << endl;
    cout << "-------------------------------------" << endl;
    pair<int, int> Horse = GetCoordinat();
    cout << "-------------------------------------" << endl << endl;

    cout << "Введите место куда надо попасть (единица): " << endl;
    cout << "-------------------------------------" << endl;
    pair<int, int> Target = GetCoordinat();
    cout << "-------------------------------------" << endl << endl;

    if (CheckingError(ChessBoard, Horse, Target))
    {
        cout << "Некорректные данные, попробуйте ещё раз!" << endl;
    }
    else
    {
        PrintChessBoard(ChessBoard, Horse, Target);
            //ниже коня:
        if ((((Horse.first + 1) == Target.first) and ((Horse.second - 2) == Target.second)) or 
            (((Horse.first + 1) == Target.first) and ((Horse.second + 2) == Target.second)) or
            (((Horse.first + 2) == Target.first) and ((Horse.second - 1) == Target.second)) or
            (((Horse.first + 2) == Target.first) and ((Horse.second + 1) == Target.second)) or
            //выше коня:
            (((Horse.first - 1) == Target.first) and ((Horse.second - 2) == Target.second)) or
            (((Horse.first - 1) == Target.first) and ((Horse.second + 2) == Target.second)) or
            (((Horse.first - 2) == Target.first) and ((Horse.second - 1) == Target.second)) or
            (((Horse.first - 2) == Target.first) and ((Horse.second + 1) == Target.second)))
        {
            cout << endl << "YEEEES";
        }
        else
        {
            cout << endl << "NOOOOO";
        }
    }
}

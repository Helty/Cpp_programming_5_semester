#include <iostream>
#include <vector>
#include <map>
#include <conio.h>
#include <utility>


using namespace std;

/*Имеется информация о проданных билетах в зале кинотеатра, число рядов в
зале равно 8 мест в каждом ряде 7. Количество проданных мест 50%. Найти
координаты 4 мест находящихся рядом, при предпочтении ближнего ряда при
условии возможности подбора мест в соседних рядах.
*/

void OutputInformationAboutMe()
{
    cout << "Шестаков Андрей БИ-31 (21 вариант)" << endl << endl;
}

vector<vector<int>> BuyingRandomTickets(int SoldPlaces, vector<vector<int>> &CinemaHall)
{
    int RandomRow;
    int RandomPlace;

    srand(time(0));
    while (SoldPlaces != 0) //заполняю зал на 50%
    {
        do
        {
            RandomPlace = 1 + rand() % CinemaHall.size();
            RandomRow = 1 + rand() % CinemaHall[0].size();
        } while (CinemaHall[RandomPlace - 1][RandomRow - 1] == 1); //генерирую заполненность, проверяю что её ещё нет в том месте что сгенерировалось.
        
        CinemaHall[RandomPlace - 1][RandomRow - 1] = 1;
        SoldPlaces--;
    }
    return CinemaHall;
}

void ShowCinemaHall(vector<vector<int>> CinemaHall)
{
    for (int Row = 0; Row < CinemaHall.size(); Row++)
    {
        cout << Row+1 << " ряд: ";
        for (int Place = 0; Place < CinemaHall[Row].size(); Place++)
        {
            cout << CinemaHall[Row][Place] << " ";
        }
        cout << endl;
    }
}

map<int, vector<pair<int, int>>> FindBestFourPlaces(vector<vector<int>> CinemaHall)
{
    vector<pair<int, int>> CoordinatesPlaces;
    map<int, vector<pair<int, int>>> ListOffers;

    for (int Row = 0; Row < CinemaHall.size(); Row++)
    {
        for (int Place = 0; Place < CinemaHall[Row].size(); Place++)
        {
            if (CinemaHall[Row][Place] == 1)
            {
                CoordinatesPlaces.clear();
                continue;
            }
            else
            {
                CoordinatesPlaces.push_back({ Row + 1, Place + 1 });
                if (CoordinatesPlaces.size() == 4)
                {
                    ListOffers[Row + 1] = CoordinatesPlaces;
                    CoordinatesPlaces.clear();
                    break;
                }
            }
        }
        CoordinatesPlaces.clear();
    }

    return ListOffers;
}

void PrintPlaces(map<int, vector<pair<int, int>>> ListCoordinatesPlaces)
{
    map <int, vector<pair<int, int>>> ::iterator it = ListCoordinatesPlaces.begin();
    for (int i = 0; it != ListCoordinatesPlaces.end(), i != 4; i++)
    {  // выводим их
        cout <<endl<< " Ряд: " << it->first << ", место: " << it->second[i].second << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    OutputInformationAboutMe();
    float Percent = 0.5;
    int Row = 8;
    int Place = 7;
    int SoldPlaces = Row * Place * Percent;

    do
    {
        system("cls");
        cout << "--------ЭКРАН--------" << endl;
        vector<vector<int>> CinemaHall(Row, vector<int>(Place, 0));
        CinemaHall = BuyingRandomTickets(SoldPlaces, CinemaHall);

        ShowCinemaHall(CinemaHall);

        map<int, vector<pair<int, int>>> ListCoordinatesPlaces = FindBestFourPlaces(CinemaHall);


        if (ListCoordinatesPlaces.empty())
        {
            cout << endl << endl << "К сожалению 4 места рядом не удалось найти.";
        }
        else
        {
            cout << endl << endl << "Самые ближайше к экрану 4 места рядом найдены!" << endl << endl;

            PrintPlaces(ListCoordinatesPlaces);
        }

        cout << endl << endl << "Для выхода нажмите ESC." << endl << endl;


    } while (_getch() != 27);

}

#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/math/special_functions/factorials.hpp>

using namespace std;

/*Дан набор данных, состоящий из 29 чисел. Реализовать перестановку и
сортировку*/

void OutputInformationAboutMe()
{
    cout << "Шестаков Андрей БИ-31 (21 вариант)" << endl << endl;
}

vector<int> GenerateRandomNumbers(int N)
{
    vector<int>RandomNumbers;
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        RandomNumbers.push_back(rand() % N);
    }

    return RandomNumbers;
}

void PrintPermutation(vector<int> RandomNumbers)
{
    for (auto NewPermutation : RandomNumbers)
    {
        cout << NewPermutation << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    unsigned int N = 29;
    
    vector<int> RandomNumbers = GenerateRandomNumbers(N);

    cout << "Ваши рандомные числа: ";

    for (int i = 0; i < RandomNumbers.size(); i++)
    {
        cout << RandomNumbers[i] << " ";
    }

    cout << endl << endl << "Ваши отсортированные числа: ";

    sort(RandomNumbers.begin(), RandomNumbers.end());

    for (int i = 0; i < RandomNumbers.size(); i++)
    {
        cout << RandomNumbers[i] << " ";
    } 
    cout << endl << endl << "Колличество перестановок из " << N << " чисел: " << boost::math::factorial<double>(N) << endl << endl;

    while (next_permutation(RandomNumbers.begin(), RandomNumbers.end()))
    {
        PrintPermutation(RandomNumbers);
    }
}

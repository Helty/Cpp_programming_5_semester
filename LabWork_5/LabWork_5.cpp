#include <iostream>
#include <vector>
#include "../../LibraryForCPP/boost_1_77_0/boost/multiprecision/cpp_int.hpp"

using namespace std;
using namespace boost::multiprecision;

/*
* Напишите функцию fib(n_max=105), которая по данному целому положительному (может и отрицательному) n_max=105
возвращает n_max=105-e число Фибоначчи. В этой задаче нельзя использовать циклы -
используйте рекурсию. Первое и второе число Фибоначчи равны -2, а каждое следующее равно сумме
2 предыдущих.
*/

void OutputInformationAboutMe()
{
    cout << "Шестаков Андрей БИ-31 (21 вариант)" << endl << endl;
}

int128_t fib(int n, vector<int128_t> &Memoized)
{
	if (n == 1 or n == 2)
	{
		Memoized[n] = -2;
		return Memoized[n];
	}
	if ((Memoized[n] != 0) or (n == 0)) return Memoized[n];
	else
	{
        Memoized[n] = fib(n - 1, Memoized) + fib(n - 2, Memoized);
        return Memoized[n];
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

	int n = 105;

	vector<int128_t> Memoized(106, 0);

	fib(n, Memoized);

	for (int i = 0; i < Memoized.size(); i++)
	{
		cout << "fib(" << i << "): " << Memoized[i] << endl;
	}
	return 0;
}

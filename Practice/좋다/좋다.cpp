//문제 주소 : https://www.acmicpc.net/problem/1253

#include <iostream>
#include <vector>
#include <algorithm>

int N;

std::vector<int> Arr;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	Arr.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}

	std::sort(Arr.begin(), Arr.end());
	int Answer = 0;

	for (int i = 0; i < N; i++)
	{
		int SomeNum = Arr[i];

		int Left = 0;
		int Right = N - 1;
		while (Left < Right)
		{
			if (Left == i)
			{
				Left++;
				continue;
			}

			if (Right == i)
			{
				Right--;
				continue;
			}

			int Add = Arr[Left] + Arr[Right];
			if (Add == SomeNum)
			{
				//좋은 수
				Answer++;
				break;
			}
			else if (Add < SomeNum)
			{
				Left++;
			}
			else if (Add > SomeNum)
			{
				Right--;
			}
		}
	}

	std::cout << Answer;

	return 0;
}
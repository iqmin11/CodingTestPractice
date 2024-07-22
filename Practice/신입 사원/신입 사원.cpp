//문제 주소 : https://www.acmicpc.net/problem/1946

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		std::cin >> N;

		std::vector<std::pair<int, int>> Arr;
		Arr.resize(N);

		for (int i = 0; i < N; i++)
		{
			std::cin >> Arr[i].first >> Arr[i].second;
		}

		std::sort(Arr.begin(), Arr.end());
		int Answer = 0;
		bool IsPossible = true;

		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (Arr[i].second > Arr[j].second)
				{
					IsPossible = false;
					break;
				}
			}

			if (IsPossible)
			{
				Answer++;
			}
		}
		
		std::cout << Answer;
	}

	return 0;
}
//문제 주소 : https://www.acmicpc.net/problem/13904

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	
	std::vector<std::pair<int, int>> HomeWork;
	HomeWork.reserve(N);
	int MaxDate = INT32_MIN;
	for (size_t i = 0; i < N; i++)
	{
		std::pair<int, int> DW;
		std::cin >> DW.first >> DW.second;
		HomeWork.push_back(DW);
		MaxDate = std::max(DW.first, MaxDate);
	}

	std::sort(HomeWork.begin(), HomeWork.end(), [](std::pair<int, int> Left, std::pair<int, int> Right)
		{
			return Left.second > Right.second;
		});

	std::vector<int> Schedule;
	Schedule.resize(MaxDate + 1, 0);

	for (int i = 0; i < N; i++)
	{
		int MinValue = INT32_MAX;
		int MinIndex = -1;
		int IsPush = false;
		for (int j = HomeWork[i].first; j > 0; --j)
		{
			if (MinValue > Schedule[j])
			{
				MinValue = Schedule[j];
				MinIndex = j;
			}

			if (Schedule[j] == 0)
			{
				IsPush = true;
				Schedule[j] = HomeWork[i].second;
				break;
			}
		}

		if (!IsPush && MinValue < HomeWork[i].second)
		{
			Schedule[MinIndex] = HomeWork[i].second;
		}
	}

	int Answer = std::accumulate(Schedule.begin(), Schedule.end(), 0);

	std::cout << Answer;
	return 0;
}
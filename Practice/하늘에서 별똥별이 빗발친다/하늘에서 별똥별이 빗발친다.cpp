// https://www.acmicpc.net/problem/14658
#include <iostream>
#include <vector>
#include <algorithm>

int N, M, L, K;
std::vector<std::pair<int, int>> StarsPos;

bool RectSizeCheck(int MinX, int MinY, int MaxX, int MaxY)
{
	return MaxX - MinX <= L && MaxY - MinY <= L;
}

int StarCount(int MinX, int MinY, int MaxX, int MaxY)
{
	int Result = 0;
	for (auto i : StarsPos)
	{
		if ((MinX <= i.first && i.first <= MaxX) && (MinY <= i.second && i.second <= MaxY))
		{
			++Result;
		}
	}

	return Result;
}

int main()
{
	std::cin >> N >> M >> L >> K;

	StarsPos.resize(K);

	for (size_t i = 0; i < K; i++)
	{
		std::cin >> StarsPos[i].first;
		std::cin >> StarsPos[i].second;
	}

	std::vector<int> SelectStart;
	SelectStart.resize(K,1);
	for (size_t i = 0; i < 2; i++)
	{
		SelectStart[i] = 0;
	}

	int Answer = INT32_MIN;

	do
	{
		std::pair<int, int> FindIndex = {-1, -1};

		for (size_t i = 0; i < K; i++)
		{
			if (SelectStart[i] == 0)
			{
				if (FindIndex.first == -1)
				{
					FindIndex.first = i;
				}
				else
				{
					FindIndex.second = i;
				}
			}
		}

		std::pair<int, int> FirstStar = StarsPos[FindIndex.first];
		std::pair<int, int> SecondStar = StarsPos[FindIndex.second];

		int MinX, MinY, MaxX, MaxY;
		if (FirstStar.first < SecondStar.first)
		{
			MinX = FirstStar.first;
			MaxX = SecondStar.first;
		}
		else
		{
			MinX = SecondStar.first;
			MaxX = FirstStar.first;
		}

		if (FirstStar.second < SecondStar.second)
		{
			MinY = FirstStar.second;
			MaxY = SecondStar.second;
		}
		else
		{
			MinY = SecondStar.second;
			MaxY = FirstStar.second;
		}

		if (!RectSizeCheck(MinX, MinY, MaxX, MaxY))
		{
			continue;
		}

		Answer = std::max(StarCount(MinX, MinY, MaxX, MaxY), Answer);

		
	} while (std::next_permutation(SelectStart.begin(), SelectStart.end()));

	std::cout << Answer;
}
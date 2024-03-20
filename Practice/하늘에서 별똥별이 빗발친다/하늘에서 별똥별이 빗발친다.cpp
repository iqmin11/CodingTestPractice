// https://www.acmicpc.net/problem/14658
#include <iostream>
#include <vector>

int dx[] = { 1,1,-1,-1, 1, 0, -1, 0 };
int dy[] = { 1,-1,1,-1, 0, 1, 0, -1 };
std::vector<std::pair<int, int>> Attack;

int DeffensCount(int StartX, int StartY, int EndX, int EndY)
{
	int X[2] = {};
	if (StartX < EndX)
	{
		X[0] = StartX;
		X[1] = EndX;
	}
	else
	{
		X[1] = StartX;
		X[0] = EndX;
	}

	int Y[2] = {};
	if (StartY < EndY)
	{
		Y[0] = StartY;
		Y[1] = EndY;
	}
	else
	{
		Y[1] = StartY;
		Y[0] = EndY;
	}
	
	int DeffensCount = 0;

	for (size_t i = 0; i < Attack.size(); i++)
	{
		if (X[0] <= Attack[i].first && Attack[i].first <= X[1]
			&& Y[0] <= Attack[i].second && Attack[i].second <= Y[1])
		{
			++DeffensCount;
		}
	}
	
	return DeffensCount;
}

int main()
{
	int N, M, L, K;

	std::cin >> N >> M >> L >> K;

	Attack.resize(K);

	for (size_t i = 0; i < K; i++)
	{
		std::cin >> Attack[i].first;
		std::cin >> Attack[i].second;
	}

	int MaxCount = INT32_MIN;

	for (size_t i = 0; i < K; i++)
	{
		std::pair<int, int> CurPos = Attack[i];
		for (size_t j = 0; j < 8; j++)
		{
			int CheckPosX = CurPos.first + (dx[j] * L);
			int CheckPosY = CurPos.second + (dy[j] * L);
			if (CheckPosX < 1)
			{
				CheckPosX = 1;
			}

			if (CheckPosY < 1)
			{
				CheckPosY = 1;
			}
			
			if (CheckPosX > N)
			{
				CheckPosX = N;
			}

			if (CheckPosY > M)
			{
				CheckPosY = M;
			}

			MaxCount = std::max(DeffensCount(CurPos.first, CurPos.second, CheckPosX, CheckPosY), MaxCount);
		}
	}

	std::cout << K - MaxCount;
}
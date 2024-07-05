//https://www.acmicpc.net/problem/1799

#include <iostream>
#include <vector>

int N;

std::vector<std::vector<int>> Grid;
std::vector<std::vector<int>> IsVisit;

void DebugRender(const std::vector<std::vector<int>>& Grid)
{
	std::cout << "////////////////////////" << std::endl;
	for (size_t y = 0; y < Grid.size(); y++)
	{
		for (size_t x = 0; x < Grid[y].size(); x++)
		{
			std::cout << Grid[y][x] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "////////////////////////" << std::endl;
}

void SetBishop(int PutX, int PutY, bool IsPut)
{
	int Weight = 1;

	if (!IsPut)
	{
		Weight = -1;
	}

	for (int x = 0; x < N; x++)
	{
		if (x == PutX)
		{
			IsVisit[PutY][PutX] += Weight;
			continue;
		}

		int CheckY1 = PutY - std::abs(x - PutX);
		int CheckY2 = PutY + std::abs(x - PutX);

		if (CheckY1 >= 0 && CheckY1 < N)
		{
			IsVisit[CheckY1][x] += Weight;
		}

		if (CheckY2 >= 0 && CheckY2 < N)
		{
			IsVisit[CheckY2][x] += Weight;
		}
	}
}

int MaxCount = INT32_MIN;
int Count = 0;
void BT(int CurIndex)
{
	if (CurIndex == N * N - 1)
	{
		MaxCount = std::max(MaxCount, Count);
		return;
	}

	int Mod = CurIndex % 2;

	if (Mod == 1)
	{
		for (int y = 0; y < N; y += 2)
		{
			for (int x = 0; x < N; x += 2)
			{

				if (Grid[y][x] == 0)
				{
					continue;
				}

				if (IsVisit[y][x] != 0)
				{
					continue;
				}

				int CheckIndex = y * N + x;

				SetBishop(x, y, true);
				Count++;
				BT(CheckIndex);
				Count--;
				SetBishop(x, y, false);
			}
		}
	}
	else if (Mod == 0)
	{
		for (int y = 0; y < N; y += 2)
		{
			for (int x = 1; x < N; x += 2)
			{

				if (Grid[y][x] == 0)
				{
					continue;
				}

				if (IsVisit[y][x] != 0)
				{
					continue;
				}

				int CheckIndex = y * N + x;

				SetBishop(x, y, true);
				Count++;
				BT(CheckIndex);
				Count--;
				SetBishop(x, y, false);
			}
		}
	}
	else
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 1; x < N; x++)
			{

				if (Grid[y][x] == 0)
				{
					continue;
				}

				if (IsVisit[y][x] != 0)
				{
					continue;
				}

				int CheckIndex = y * N + x;

				SetBishop(x, y, true);
				Count++;
				BT(CheckIndex);
				Count--;
				SetBishop(x, y, false);
			}
		}
	}
}

int main()	
{
	std::cin >> N;
	Grid.resize(N);
	IsVisit.resize(N);
	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(N);
		IsVisit[y].resize(N, 0);
		for (int x = 0; x < N; x++)
		{
			std::cin >> Grid[y][x];
		}
	}

	BT(-1);

	std::cout << MaxCount;
	return 0;
}


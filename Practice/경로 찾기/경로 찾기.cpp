//문제 주소 : https://www.acmicpc.net/problem/11403

#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> Grid;
const int INF = 100001;

void FW()
{
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				Grid[i][j] = std::min(Grid[i][j], Grid[i][k] + Grid[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Grid[i][j] >= INF ? Grid[i][j] = 0 : Grid[i][j] = 1;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	Grid.resize(N);
	for (int i = 0; i < N; i++)
	{
		Grid[i].resize(N);
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int temp;
			std::cin >> temp;
			if (temp == 0)
			{
				Grid[y][x] = INF;
			}
			else
			{
				Grid[y][x] = temp;
			}
		}
	}

	FW();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << Grid[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}
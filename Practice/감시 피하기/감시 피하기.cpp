//문제 주소 : https://www.acmicpc.net/problem/18428

#include <iostream>
#include <vector>

int N;
std::vector<std::vector<char>> Grid;
std::vector<std::pair<int, int>> TArr;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

bool Search(std::pair<int, int> CurIndex, int Dir)
{
	if (Grid[CurIndex.second][CurIndex.first] == 'S')
	{
		return true;
	}

	int CheckX = CurIndex.first + dx[Dir];
	int CheckY = CurIndex.second + dy[Dir];

	if (CheckX < 0 || CheckY < 0 || CheckX >= N || CheckY >= N)
	{
		return false;
	}

	if (Grid[CheckY][CheckX] == 'O')
	{
		return false;
	}

	return Search(std::make_pair(CheckX, CheckY), Dir);
}

bool AnyTeacherFind()
{
	for (int i = 0; i < TArr.size(); i++)
	{
		for (int Dir = 0; Dir < 4; Dir++)
		{
			if (Search(TArr[i], Dir))
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	
	Grid.resize(N);

	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(N);
		for (int x = 0; x < N; x++)
		{
			std::cin >> Grid[y][x];
			if (Grid[y][x] == 'T')
			{
				TArr.push_back(std::make_pair(x,y));
			}
		}
	}

	int NN = N * N;

	bool IsSuccess = false;

	for (int i = 0; i < NN - 2; i++)
	{
		std::pair<int, int> Ob1;
		Ob1.first = i % N;
		Ob1.second = i / N;
		if (Grid[Ob1.second][Ob1.first] != 'X')
		{
			continue;
		}

		Grid[Ob1.second][Ob1.first] = 'O';
		for (int j = i + 1; j < NN - 1; j++)
		{
			std::pair<int, int> Ob2;
			Ob2.first = j % N;
			Ob2.second = j / N;
			if (Grid[Ob2.second][Ob2.first] != 'X')
			{
				continue;
			}

			Grid[Ob2.second][Ob2.first] = 'O';
			for (int k = j + 1; k < NN; k++)
			{
				std::pair<int, int> Ob3;
				Ob3.first = k % N;
				Ob3.second = k / N;
				if (Grid[Ob3.second][Ob3.first] != 'X')
				{
					continue;
				}

				Grid[Ob3.second][Ob3.first] = 'O';
				if (IsSuccess = !AnyTeacherFind())
				{
					std::cout << "YES";
					return 0;
				}
				Grid[Ob3.second][Ob3.first] = 'X';
			}
			Grid[Ob2.second][Ob2.first] = 'X';
		}
		Grid[Ob1.second][Ob1.first] = 'X';
	}

	std::cout << "NO";

	return 0;
}
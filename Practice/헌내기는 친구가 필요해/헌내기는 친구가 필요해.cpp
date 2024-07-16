//문제 주소 : https://www.acmicpc.net/problem/21736

#include <iostream>
#include <vector>
#include <string>

int Y, X;
std::vector<std::string> Grid;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int Answer = 0;

void DFS(std::pair<int, int> CurPos)
{
	Grid[CurPos.second][CurPos.first] = 'X';

	for (int i = 0; i < 4; i++)
	{
		int CheckX = CurPos.first + dx[i];
		int CheckY = CurPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= X || CheckY >= Y)
		{
			continue;
		}

		if (Grid[CheckY][CheckX] == 'X')
		{
			continue;
		}

		if (Grid[CheckY][CheckX] == 'P')
		{
			Answer++;
		}

		DFS(std::make_pair(CheckX, CheckY));
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> Y >> X;

	Grid.resize(Y);
	for (int y = 0; y < Y; y++)
	{
		std::cin >> Grid[y];
	}

	std::pair<int, int> StartPos = {-1, -1};
	std::pair<int, int> FalseCheck = { -1, -1 };

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (Grid[y][x] == 'I')
			{
				StartPos = std::make_pair(x, y);

				break;
			}
		}

		if (StartPos != FalseCheck)
		{
			break;
		}
	}

	DFS(StartPos);

	if (Answer == 0)
	{
		std::cout << "TT";
		return 0;
	}

	std::cout << Answer;

	return 0;
}
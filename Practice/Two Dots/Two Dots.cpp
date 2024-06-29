//문제 주소 : https://www.acmicpc.net/problem/16929

#include <iostream>
#include <vector>

int Y, X;
std::vector<std::vector<char>> Grid;
std::vector<std::vector<bool>> IsVisit;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void DFS(std::pair<int, int> CurPos, std::pair<int, int> StartPos, int& Depth)
{
	IsVisit[CurPos.second][CurPos.first] = true;
	Depth++;

	for (int i = 0; i < 4; i++)
	{
		int CheckX = CurPos.first + dx[i];
		int CheckY = CurPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= X || CheckY >= Y)
		{
			continue;
		}

		if (Grid[CurPos.second][CurPos.first] != Grid[CheckY][CheckX])
		{
			continue;
		}

		std::pair<int, int> CheckPos = std::make_pair(CheckX, CheckY);

		if (CheckPos == StartPos && Depth >= 4)
		{
			std::cout << "Yes";
			::exit(0);
		}

		if (IsVisit[CheckY][CheckX])
		{
			continue;
		}

		DFS(CheckPos, StartPos, Depth);
	}

	Depth--;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> Y >> X;

	Grid.resize(Y);
	IsVisit.resize(Y);

	for (int y = 0; y < Y; y++)
	{
		Grid[y].resize(X);
		IsVisit[y].resize(X, false);
		for (int x = 0; x < X; x++)
		{
			std::cin >> Grid[y][x];
		}
	}

	int Depth = 0;
	std::vector<std::vector<bool>> Init = IsVisit;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			DFS({x,y}, {x,y}, Depth);
			IsVisit = Init;
		}
	}

	std::cout << "No";

	return 0;
}
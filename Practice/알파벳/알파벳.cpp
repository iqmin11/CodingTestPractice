//https://www.acmicpc.net/problem/1987

#include <iostream>
#include <vector>

int R, C;
std::vector<std::vector<char>> Grid;
std::vector<std::vector<bool>> IsVisit;
std::vector<bool> IsVisitThisAlphabet;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int CurPathSize = 0;
int MaxPathSize = INT32_MIN;

void DFS(std::pair<int, int> CurPos)
{
	IsVisit[CurPos.second][CurPos.first] = true;
	char CurAlphabet = Grid[CurPos.second][CurPos.first];
	IsVisitThisAlphabet[CurAlphabet - 'A'] = true;
	CurPathSize++;

	MaxPathSize = std::max(MaxPathSize, CurPathSize);

	for (int i = 0; i < 4; i++)
	{
		int CheckX = CurPos.first + dx[i];
		int CheckY = CurPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= C || CheckY >= R)
		{
			continue;
		}

		if (IsVisit[CheckY][CheckX])
		{
			continue;
		}

		if (IsVisitThisAlphabet[Grid[CheckY][CheckX] - 'A'])
		{
			continue;
		}

		DFS(std::make_pair(CheckX, CheckY));
	}

	IsVisit[CurPos.second][CurPos.first] = false;
	IsVisitThisAlphabet[CurAlphabet - 'A'] = false;
	CurPathSize--;
}

int main()
{
	IsVisitThisAlphabet.resize('Z' - 'A' + 1);

	for (char i = 'A'; i <= 'Z'; i++)
	{
		IsVisitThisAlphabet[i - 'A'] = false;
	}

	std::cin >> R >> C;
	
	Grid.resize(R);
	IsVisit.resize(R);

	for (int i = 0; i < R; i++)
	{
		Grid[i].resize(C);
		IsVisit[i].resize(C, false);
		for (int j = 0; j < C; j++)
		{
			std::cin >> Grid[i][j];
		}
	}

	DFS({0,0});

	std::cout << MaxPathSize;

	return 0;
}
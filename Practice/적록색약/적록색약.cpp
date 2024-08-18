//문제 주소 : https://www.acmicpc.net/problem/10026

#include <iostream>
#include <vector>
#include <functional>

int N;
std::vector<std::string> Grid;
std::vector<std::vector<bool>> IsVisit;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

bool CorrectColorDecision(char Comp0, char Comp1)
{
	return Comp0 == Comp1;
}

bool WrongColorDecision(char Comp0, char Comp1)
{
	char TransComp0 = (Comp0 == 'R' ? 'G' : Comp0);
	char TransComp1 = (Comp1 == 'R' ? 'G' : Comp1);

	return TransComp0 == TransComp1;
}

void DFS(std::pair<int, int> CurPos, std::function<bool(char, char)> ColorDecision)
{
	IsVisit[CurPos.second][CurPos.first] = true;

	for (int i = 0; i < 4; i++)
	{
		int CheckX = CurPos.first + dx[i];
		int CheckY = CurPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= N || CheckY >= N)
		{
			continue;
		}

		if (IsVisit[CheckY][CheckX])
		{
			continue;
		}

		if (!ColorDecision(Grid[CheckY][CheckX], Grid[CurPos.second][CurPos.first]))
		{
			continue;
		}

		DFS(std::make_pair(CheckX, CheckY), ColorDecision);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	Grid.resize(N);
	IsVisit.resize(N);
	for (int y = 0; y < N; y++)
	{
		IsVisit[y].resize(N, false);
		std::cin >> Grid[y];
	}


	int CorrectColorReleam = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (IsVisit[y][x])
			{
				continue;
			}
			++CorrectColorReleam;
			DFS(std::make_pair(x, y), CorrectColorDecision);
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			IsVisit[y][x] = false;
		}
	}

	int WrongColorReleam = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (IsVisit[y][x])
			{
				continue;
			}
			++WrongColorReleam;
			DFS(std::make_pair(x, y), WrongColorDecision);
		}
	}

	std::cout << CorrectColorReleam << ' ' << WrongColorReleam;

	return 0;
}
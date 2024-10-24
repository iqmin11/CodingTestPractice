//문제 주소 : https://www.acmicpc.net/problem/17142

#include <iostream>
#include <vector>
#include <deque>
#include <queue>

int N, VirusCount;
std::vector<std::pair<int, int>> CanVirusPos;
std::vector<std::vector<int>> Grid;
std::vector<std::vector<int>> IsVisit;
int VoidCount = 0;

std::deque<int> SelectIndexs;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void DebugRender()
{
	std::cout << "///////////////////\n";
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (IsVisit[y][x] != -1)
			{
				std::cout << IsVisit[y][x];
			}
			else
			{
				std::cout << 'X';
			}
		}
		std::cout << '\n';
	}
	std::cout << "///////////////////\n";
}

int BFS(const std::deque<int>& StartCpy, int VoidCount)
{
	std::queue<std::pair<int, int>> q;
	int Result = INT32_MIN;
	for (auto& i : StartCpy)
	{
		int StartX = CanVirusPos[i].first;
		int StartY = CanVirusPos[i].second;
		IsVisit[StartY][StartX] = 0;
		q.push(CanVirusPos[i]);

		if (Grid[StartY][StartX] == 0)
		{
			VoidCount--;
		}

		if (VoidCount == 0)
		{
			return IsVisit[StartY][StartX];
		}
	}

	while (!q.empty())
	{
		std::pair<int, int> CurPos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int CheckX = CurPos.first + dx[i];
			int CheckY = CurPos.second + dy[i];

			if (CheckX < 0 || CheckY < 0 || CheckX >= N || CheckY >= N)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] == 1)
			{
				continue;
			}

			if (IsVisit[CheckY][CheckX] != -1)
			{
				continue;
			}

			q.push(std::make_pair(CheckX, CheckY));
			IsVisit[CheckY][CheckX] = IsVisit[CurPos.second][CurPos.first] + 1;

			Result = std::max(IsVisit[CheckY][CheckX], Result);

			if (Grid[CheckY][CheckX] == 0)
			{
				VoidCount--;
			}

			if (VoidCount == 0)
			{
				return IsVisit[CheckY][CheckX];
			}
		}
	}

	if (VoidCount != 0)
	{
		return INT32_MAX;
	}

	return Result;
}

int Answer = INT32_MAX;

void SelectVirusPos(int CurIndex)
{
	if (SelectIndexs.size() == VirusCount)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				IsVisit[y][x] = -1;
			}
		}

		Answer = std::min(BFS(SelectIndexs, VoidCount), Answer);
		DebugRender();
		return;
	}

	for (int i = CurIndex; i < CanVirusPos.size(); i++)
	{
		SelectIndexs.push_back(i);
		SelectVirusPos(i + 1);
		SelectIndexs.pop_back();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> VirusCount;

	Grid.resize(N);
	IsVisit.resize(N);
	VoidCount = N * N;
	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(N);
		IsVisit[y].resize(N, -1);
		for (int x = 0; x < N; x++)
		{
			int temp;
			std::cin >> temp;

			if (temp == 0)
			{
				Grid[y][x] = 0;
			}
			else if (temp == 1)
			{
				Grid[y][x] = 1;
				VoidCount--;
			}
			else
			{
				Grid[y][x] = 2;
				CanVirusPos.push_back(std::make_pair(x, y));
			}
		}
	}

	VoidCount -= CanVirusPos.size();

	SelectVirusPos(0);

	if (Answer == INT32_MAX)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << Answer;
	}

	return 0;
}
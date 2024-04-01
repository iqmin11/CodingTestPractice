// https://www.acmicpc.net/problem/2169

#include <iostream>
#include <vector>
#include <stack>

std::vector<std::vector<int>> Cost;
std::vector<std::vector<bool>> IsVisit;

int N, M;
int dx[] = {-1, 1, 0};
int dy[] = {0, 0, 1};

//00 Ãâ¹ß, M-1 M-1 µµÂø

std::stack<std::pair<int, int>> RecordPath;
int PathValue = 0;
void DFS(std::pair<int, int> CurPos)
{
	IsVisit[CurPos.second][CurPos.first] = true;
	RecordPath.push(CurPos);
	PathValue += Cost[CurPos.second][CurPos.first];

	for (size_t i = 0; i < 3; i++)
	{
		int CheckX = CurPos.first + dx[i];
		int CheckY = CurPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckX >= N)
		{
			continue;
		}

		if (IsVisit[CheckY][CheckX])
		{
			continue;
		}

		DFS(std::make_pair(CheckX, CheckY));
	}

	RecordPath.pop();
	IsVisit[CurPos.second][CurPos.first] = false;
	PathValue -= Cost[CurPos.second][CurPos.first];
}

int main()
{
	std::cin >> N >> M;
	Cost.resize(N);
	IsVisit.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		Cost[i].resize(M);
		IsVisit[i].resize(M, false);
		for (size_t j = 0; j < M; j++)
		{
			std::cin >> Cost[i][j];
		}
	}
}
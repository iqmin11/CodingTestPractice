//https://www.acmicpc.net/problem/14500

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>

int dx[] = { 1,0,-1 };
int dy[] = { 0,1,0 };
int N, M;

std::vector<std::vector<int>> Grid;
std::vector<std::vector<bool>> IsVisit;

//ㅗ모양을 제외한 나머지 모양의 테트로 머시기를 찾을 수 있음
int RecordCount = 0; // 기록한 블록 갯수
int RecordValue = 0; //기록한 점수
int MaxValue = INT32_MIN;

void DFS(std::pair<int, int> CurPos)
{
	IsVisit[CurPos.second][CurPos.first] = true;
	++RecordCount;
	RecordValue += Grid[CurPos.second][CurPos.first];

	if (RecordCount == 4)
	{
		MaxValue = std::max(MaxValue, RecordValue);
		IsVisit[CurPos.second][CurPos.first] = false;
		--RecordCount;
		RecordValue -= Grid[CurPos.second][CurPos.first];
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		int CheckX = CurPos.first + dx[i];
		int CheckY = CurPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
		{
			continue;
		}

		if (IsVisit[CheckY][CheckX])
		{
			continue;
		}

		DFS(std::make_pair(CheckX, CheckY));
	}

	IsVisit[CurPos.second][CurPos.first] = false;
	--RecordCount;
	RecordValue -= Grid[CurPos.second][CurPos.first];
}

int Tdx[] = {1, 0 ,-1 ,0};
int Tdy[] = {0, 1, 0, -1};

std::vector<std::vector<int>> Combination;

void TCheck(std::pair<int, int> CurPos)
{
	for (int i = 0; i < 4; i++)
	{
		int CheckValue = Grid[CurPos.second][CurPos.first];

		for (int j = 0; j < 3; j++)
		{
			int CheckX = CurPos.first + Tdx[Combination[i][j]];
			int CheckY = CurPos.second + Tdy[Combination[i][j]];

			if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
			{
				break;
			}

			CheckValue += Grid[CheckY][CheckX];
		}

		MaxValue = std::max(CheckValue, MaxValue);
	}
}


int main()
{
	std::cin >> N >> M;

	Grid.resize(N);
	IsVisit.resize(N);

	Combination.reserve(4);
	Combination.push_back({0,1,2});
	Combination.push_back({0,1,3});
	Combination.push_back({0,2,3});
	Combination.push_back({1,2,3});

	for (int i = 0; i < N; i++)
	{
		Grid[i].resize(M);
		IsVisit[i].resize(M, false);
		for (int j = 0; j < M; j++)
		{
			std::cin >> Grid[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			DFS(std::make_pair(j, i));
			TCheck(std::make_pair(j, i));
		}
	}

	std::cout << MaxValue;

	return 0;
}
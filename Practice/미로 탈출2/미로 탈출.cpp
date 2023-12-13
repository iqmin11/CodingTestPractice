#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

std::vector<std::vector<int>> Field;
std::vector<std::vector<std::vector<std::pair<int, int>>>> LinkNodes;
std::vector<std::vector<std::vector<bool>>> IsVisit;
std::pair<int, int> StartIndex;
std::pair<int, int> GoalIndex;
std::vector<std::pair<int, int>> WallIndex;
std::vector<std::vector<std::vector<int>>> Depth;

int BFS(std::pair<int, int> _Start, std::pair<int, int> _End)
{
	std::queue<std::pair<std::pair<int, int>, bool>> q; //ÁÂÇ¥, ÁöÆÎÀÌ »ç¿ë À¯¹«
	IsVisit[_Start.second][_Start.first][0] = true;
	IsVisit[_Start.second][_Start.first][1] = true;
	q.push({ _Start, false });
	Depth[_Start.second][_Start.first][0] = 0;
	Depth[_Start.second][_Start.first][1] = 0;

	while (!q.empty())
	{
		std::pair<int, int> Check = q.front().first;
		bool UseMagic = q.front().second;

		if (Check == _End)
		{
			return Depth[Check.second][Check.first][static_cast<int>(UseMagic)];
		}

		q.pop();

		for (auto& LinkNode : LinkNodes[Check.second][Check.first])
		{
			if (UseMagic == false)
			{
				if (!IsVisit[LinkNode.second][LinkNode.first][1] && Field[LinkNode.second][LinkNode.first] == 1)
				{
					q.push({ LinkNode, true });
					IsVisit[LinkNode.second][LinkNode.first][1] = true;
					Depth[LinkNode.second][LinkNode.first][1] = Depth[Check.second][Check.first][1] + 1;
				}

				if (!IsVisit[LinkNode.second][LinkNode.first][0] && Field[LinkNode.second][LinkNode.first] == 0)
				{
					q.push({ LinkNode, false });
					IsVisit[LinkNode.second][LinkNode.first][0] = true;
					Depth[LinkNode.second][LinkNode.first][0] = Depth[Check.second][Check.first][0] + 1;
				}
			}
			else
			{
				if (!IsVisit[LinkNode.second][LinkNode.first][1] && Field[LinkNode.second][LinkNode.first] == 0)
				{
					q.push({ LinkNode, false });
					IsVisit[LinkNode.second][LinkNode.first][1] = true;
					Depth[LinkNode.second][LinkNode.first][1] = Depth[Check.second][Check.first][1] + 1;
				}
			}
		}
	}

	return -1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M, Sx, Sy, Gx, Gy;
	std::cin >> N >> M >> Sy >> Sx >> Gy >> Gx;

	StartIndex = { Sx-1, Sy-1 };
	GoalIndex = { Gx-1, Gy-1 };

	WallIndex.reserve(N*M);

	IsVisit.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		IsVisit[i].resize(M);
		for (size_t j = 0; j < M; j++)
		{
			IsVisit[i][j].resize(2, false);
		}
	}

	Field.resize(N);
	for (size_t y = 0; y < N; y++)
	{
		Field[y].resize(M);
		for (size_t x = 0; x < M; x++)
		{
			int Info;
			std::cin >> Info;

			Field[y][x] = Info;

			if (Info == 1)
			{
				WallIndex.emplace_back(std::make_pair(x,y));
				//IsVisit[y][x][0] = true;
				//IsVisit[y][x][1] = true;
			}
		}
	}

	LinkNodes.resize(N);
	for (size_t y = 0; y < N; y++)
	{
		LinkNodes[y].resize(M);
		for (size_t x = 0; x < M; x++)
		{
			LinkNodes[y][x].reserve(4);
			for (size_t i = 0; i < 4; i++)
			{
				int CheckX = x + dx[i];
				int CheckY = y + dy[i];

				if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
				{
					continue;
				}

				LinkNodes[y][x].emplace_back(std::make_pair(CheckX, CheckY));
			}
		}
	}

	Depth.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		Depth[i].resize(M);
		for (size_t j = 0; j < Depth[i].size(); j++)
		{
			Depth[i][j].resize(2,0);
		}
	}

	std::vector<std::vector<std::vector<bool>>> InitVisitData = IsVisit;

	std::cout << BFS(StartIndex, GoalIndex);

	return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <queue>

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

std::vector<std::vector<int>> Field;
std::vector<std::vector<std::set<std::pair<int, int>>>> LinkNodes;
std::vector<std::vector<bool>> IsVisit;
std::pair<int, int> StartIndex;
std::pair<int, int> GoalIndex;
std::vector<std::pair<int, int>> WallIndex;
std::vector<std::vector<int>> Depth;

int BFS(std::pair<int, int> _Start, std::pair<int, int> _End, std::pair<int, int> _Distroy)
{
	std::queue<std::pair<int, int>> q;
	IsVisit[_Distroy.second][_Distroy.first] = false;
	IsVisit[_Start.second][_Start.first] = true;
	q.push(_Start);
	Depth[_Start.second][_Start.first] = 0;

	while (!q.empty())
	{
		std::pair<int, int> Check = q.front();
		q.pop();

		for (auto& LinkNode : LinkNodes[Check.second][Check.first])
		{
			if (!IsVisit[LinkNode.second][LinkNode.first])
			{
				IsVisit[LinkNode.second][LinkNode.first] = true;
				Depth[LinkNode.second][LinkNode.first] = Depth[Check.second][Check.first] + 1;
				if (LinkNode == GoalIndex)
				{
					return Depth[LinkNode.second][LinkNode.first];
				}
				q.push(LinkNode);
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

	Field.resize(N);
	WallIndex.reserve(N*M);

	IsVisit.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		IsVisit[i].resize(M, false);
	}

	for (size_t y = 0; y < N; y++)
	{
		Field.reserve(M);
		for (size_t x = 0; x < M; x++)
		{
			int Info;
			std::cin >> Info;
			Field[y].emplace_back(Info);

			if (Info == 1)
			{
				WallIndex.emplace_back(std::make_pair(x,y));
				IsVisit[y][x] = true;
			}
		}
	}

	LinkNodes.resize(N);
	for (size_t y = 0; y < N; y++)
	{
		LinkNodes[y].resize(M);
		for (size_t x = 0; x < M; x++)
		{
			for (size_t i = 0; i < 4; i++)
			{
				int CheckX = x + dx[i];
				int CheckY = y + dy[i];

				if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
				{
					continue;
				}

				LinkNodes[y][x].insert(std::make_pair(CheckX, CheckY));
			}
		}
	}

	Depth.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		Depth[i].resize(M, 0);
	}

	std::vector<std::vector<bool>> InitVisitData = IsVisit;
	int answer = INT32_MAX;

	for (size_t i = 0; i < WallIndex.size(); i++)
	{
		answer = std::min(BFS(StartIndex, GoalIndex, WallIndex[i]), answer);
		IsVisit = InitVisitData;
	}

	std::cout << answer;

	return 0;
}
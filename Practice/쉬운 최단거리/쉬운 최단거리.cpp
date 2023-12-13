#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <iterator>

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

std::vector<std::vector<int>> Field;
std::vector<std::vector<std::set<std::pair<int, int>>>> LinkNodes;
std::vector<std::vector<bool>> IsVisit;
std::pair<int, int> StartPos;
std::vector<std::pair<int, int>> WallPos;

void Init()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

std::vector<std::vector<int>> BFS(std::pair<int, int> _Start)
{
	std::vector<std::vector<int>> Depth;
	Depth.resize(Field.size());
	for (int y = 0; y < Depth.size(); y++)
	{
		Depth[y].resize(Field[y].size(), -1);
	}

	for (int i = 0; i < WallPos.size(); i++)
	{
		Depth[WallPos[i].second][WallPos[i].first] = 0;
	}

	std::queue<std::pair<int, int>> q;
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
				q.push(LinkNode);
				Depth[LinkNode.second][LinkNode.first] = Depth[Check.second][Check.first] + 1;
			}
		}
	}

	return Depth;
}

int main()
{
	Init();

	int N, M;
	std::cin >> N >> M;

	IsVisit.resize(N);
	for (int y = 0; y < N; y++)
	{
		IsVisit[y].resize(M, false);
	}

	Field.resize(N);
	WallPos.reserve(N*M);
	for (int y = 0; y < N; y++)
	{
		Field.reserve(M);
		for (int x = 0; x < M; x++)
		{
			int option;
			std::cin >> option;
			switch (option)
			{
			case 0:
				Field[y].emplace_back(0);
				WallPos.emplace_back(std::make_pair(x,y));
				break;
			case 1:
				Field[y].emplace_back(1);
				break;
			case 2:
				Field[y].emplace_back(1);
				StartPos = {x,y};
				break;
			default:
				break;
			}
		}
	}

	LinkNodes.resize(N);
	for (int y = 0; y < N; y++)
	{
		LinkNodes[y].resize(M);
		for (int x = 0; x < M; x++)
		{
			if (Field[y][x] == 0)
			{
				continue;
			}

			for (int i = 0; i < 4; i++)
			{
				int CheckX = x + dx[i];
				int CheckY = y + dy[i];

				if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N || Field[CheckY][CheckX] == 0)
				{
					continue;
				}

				LinkNodes[y][x].insert({ CheckX , CheckY });
			}
		}
	}

	std::vector<std::vector<int>> Answer = BFS(StartPos);

	for (size_t y = 0; y < Answer.size(); y++)
	{
		std::copy(Answer[y].begin(), Answer[y].end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << "\n";
	}

	return 0;
}

//문제 주소 : https://www.acmicpc.net/problem/1584

#include <iostream>
#include <vector>
#include <queue>
#include <set>

int Grid[501][501] = { {0,}, };
bool IsVisit[501][501] = { {0,}, };

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int Dij(std::pair<int, int> StartIndex)
{
	std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
	std::vector<std::vector<int>> Dist;
	Dist.resize(501);
	for (int i = 0; i <= 500; i++)
	{
		Dist[i].resize(501, INT32_MAX);
	}

	Dist[StartIndex.second][StartIndex.first] = 0;
	pq.push(std::make_pair(-Dist[StartIndex.second][StartIndex.first], StartIndex));

	while (!pq.empty())
	{
		int CurCost = -pq.top().first;
		std::pair<int, int> CurNode = pq.top().second;
		pq.pop();

		if (CurCost > Dist[CurNode.second][CurNode.first])
		{
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int CheckX = CurNode.first + dx[i];
			int CheckY = CurNode.second + dy[i];

			if (CheckX < 0 || CheckY < 0 || CheckX > 500 || CheckY > 500)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] == 2)
			{
				continue;
			}

			int EdgeCost = 0;

			if (Grid[CheckY][CheckX] == 1)
			{
				EdgeCost = 1;
			}

			int ViaCost = CurCost + EdgeCost;
			if (ViaCost < Dist[CheckY][CheckX])
			{
				Dist[CheckY][CheckX] = ViaCost;
				IsVisit[CheckY][CheckX] = true;
				pq.push(std::make_pair(-ViaCost, std::make_pair(CheckX, CheckY)));
			}
		}
	}

	if (IsVisit[500][500] == false)
	{
		return -1;
	}

	return Dist[500][500];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//위험구역 설정
	int N;
	std::cin >> N;
	
	//위험구역 설정
	for (size_t i = 0; i < N; i++)
	{
		int Left, Right, Top, Bottom;
		std::cin >> Left >> Top >> Right >> Bottom;

		if (Left > Right)
		{
			std::swap(Left, Right);
		}

		if (Top > Bottom)
		{
			std::swap(Top, Bottom);
		}

		for (int y = Top; y <= Bottom; y++)
		{
			for (int x = Left; x <= Right; x++)
			{
				Grid[y][x] = 1;
			}
		}
	}
	
	std::cin >> N;
	//죽음구역 설정
	for (size_t i = 0; i < N; i++)
	{
		int Left, Right, Top, Bottom;
		std::cin >> Left >> Top >> Right >> Bottom;

		if (Left > Right)
		{
			std::swap(Left, Right);
		}

		if (Top > Bottom)
		{
			std::swap(Top, Bottom);
		}

		for (int y = Top; y <= Bottom; y++)
		{
			for (int x = Left; x <= Right; x++)
			{
				Grid[y][x] = 2;
			}
		}
	}

	std::cout << Dij(std::make_pair(0, 0));

	return 0;
}
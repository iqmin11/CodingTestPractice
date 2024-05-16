//문제 주소 : https://www.acmicpc.net/problem/17086

#include <iostream>
#include <queue>

int N, M;

std::vector<std::pair<int, int>> Sharks;
std::vector<std::vector<bool>> IsVisit;

int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };

std::vector<std::vector<int>> BFS(std::pair<int, int> StartPos)
{
	std::queue<std::pair<int, int>> q;
	IsVisit[StartPos.second][StartPos.first] = true;
	q.push(StartPos);

	std::vector<std::vector<int>> Depth;

	Depth.resize(N);
	for (int i = 0; i < N; i++)
	{
		Depth[i].resize(M, 0);
	}

	while (!q.empty())
	{
		std::pair<int, int> CurPos = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
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

			q.push(std::make_pair(CheckX, CheckY));
			IsVisit[CheckY][CheckX] = true;

			Depth[CheckY][CheckX] = Depth[CurPos.second][CurPos.first] + 1;
		}
	}

	return Depth;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	std::vector<std::vector<int>> Answer;
	Answer.resize(N);
	IsVisit.resize(N);
	for (int y = 0; y < N; y++)
	{
		Answer[y].resize(M, INT32_MAX);
		IsVisit[y].resize(M, false);
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			int temp;
			std::cin >> temp;
			if (temp == 1)
			{
				Sharks.push_back(std::make_pair(x, y));
			}
		}
	}

	std::vector<std::vector<bool>> Init = IsVisit;

	for (int i = 0; i < Sharks.size(); i++)
	{
		IsVisit = Init;
		std::vector<std::vector<int>> Result = BFS(Sharks[i]);

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				Answer[y][x] = std::min(Result[y][x], Answer[y][x]);
			}
		}
	}

	int MaxValue = INT32_MIN;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			MaxValue = std::max(MaxValue, Answer[y][x]);
		}
	}

	std::cout << MaxValue;

	return 0;
}
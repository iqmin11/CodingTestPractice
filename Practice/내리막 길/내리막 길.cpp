//���� �ּ� : https://www.acmicpc.net/problem/1520

#include <iostream>
#include <vector>
#include <queue>

int Y, X;
std::vector<std::vector<int>> Grid;
std::vector<std::vector<int>> DP; //DP[a][b] = c  -> a, b���� Y-1, X-1���� c���� ��ΰ� �ִ�

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void DebugRender(const std::vector<std::vector<int>>& Grid)
{
	std::cout << "////////////////////" << std::endl;
	for (int y = 0; y < Grid.size(); y++)
	{
		for (int x = 0; x < Grid[y].size(); x++)
		{
			std::cout << Grid[y][x] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "////////////////////" << std::endl;
}

std::pair<int, int> DestNode;
int DFS(std::pair<int, int> CurNode)
{
	if (CurNode == DestNode)
	{
		return 1;
	}

	if (DP[CurNode.second][CurNode.first] != -1)
	{
		//�̹� �鷶�� ���̸� ����ġ��, �鸮�� �ʾҴٸ� DFS�� ���Ƽ� ������������ ��� ������ ���ؾ���
		return DP[CurNode.second][CurNode.first];
	}

	DP[CurNode.second][CurNode.first] = 0;

	for (int i = 0; i < 4; i++)
	{
		int CheckX = CurNode.first + dx[i];
		int CheckY = CurNode.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= X || CheckY >= Y)
		{
			continue;
		}

		if (Grid[CurNode.second][CurNode.first] <= Grid[CheckY][CheckX])
		{
			continue;
		}
		
		DP[CurNode.second][CurNode.first] = DP[CurNode.second][CurNode.first] + DFS(std::make_pair(CheckX, CheckY));
	}

	DebugRender(DP);
	return DP[CurNode.second][CurNode.first];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> Y >> X;
	Grid.resize(Y);
	DP.resize(Y);
	DestNode = { X - 1, Y - 1 };

	for (int y = 0; y < Y; y++)
	{
		Grid[y].resize(X);
		DP[y].resize(X, -1);
		for (int x = 0; x < X; x++)
		{
			std::cin >> Grid[y][x];
		}
	}

	DFS({0,0});

	std::cout << DP[0][0];

	return 0;
}
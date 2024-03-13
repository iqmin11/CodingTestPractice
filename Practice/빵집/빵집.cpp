//https://www.acmicpc.net/problem/3109

#include <iostream>
#include <vector>
#include <stack>

int R, C;
std::vector<std::vector<char>> Grid;

int dx[] = {1,1,1};
int dy[] = {-1,0,1};

int Count = 0;

void DebugRender()
{
	std::cout << "//////////////////////\n";
	for (size_t i = 0; i < R; i++)
	{
		for (size_t j = 0; j < C; j++)
		{
			std::cout << Grid[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "//////////////////////\n";
}

std::stack<std::pair<int, int>> RecordStack;
std::stack<std::pair<int, int>> RecordStack2;

bool DFS(std::pair<int, int> _StartPos)
{
	std::pair<int, int> CurPos = _StartPos;
	Grid[CurPos.second][CurPos.first] = 'x';
	RecordStack.push(_StartPos);

	if (_StartPos.first == C-1)
	{
		++Count;
		return true;
	}

	for (size_t i = 0; i < 3; i++)
	{
		int CheckX = CurPos.first + dx[i];
		int CheckY = CurPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= C || CheckY >= R)
		{
			continue;
		}

		if (Grid[CheckY][CheckX] == 'x')
		{
			continue;
		}

		if (DFS({ CheckX ,CheckY }))
		{
			return true;
		}
	}

	return false;
}

int main()
{
	std::cin >> R >> C;
	Grid.resize(R);
	for (size_t i = 0; i < R; i++)
	{
		Grid[i].resize(C);
		for (size_t j = 0; j < C; j++)
		{
			std::cin >> Grid[i][j];
		}
	}

	for (size_t i = 0; i < R; i++)
	{
		DFS({ 0,i });
		while (!RecordStack.empty())
		{
			std::pair<int, int> Top = RecordStack.top();
			RecordStack.pop();
			Grid[Top.second][Top.first] = 'x';
		}
	}

	std::cout << Count;
}
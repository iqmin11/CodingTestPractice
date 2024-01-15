#include <iostream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dx[] = {0,1,-1};
int dy[] = {1,0,-1};

std::vector<std::vector<int>> TriArr;

void DebugRender()
{
	for (size_t y = 0; y < TriArr.size(); y++)
	{
		for (size_t x = 0; x < TriArr[y].size(); x++)
		{
			std::cout << TriArr[y][x];
		}
		std::cout << std::endl;
	}
}

void DFS(int _StartX, int _StartY)
{
	TriArr[_StartY][_StartX] = 1;
	DebugRender();
	for (size_t i = 0; i < 3; i++)
	{
		int CheckX = _StartX + dx[i];
		int CheckY = _StartY + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckY >= TriArr.size() || CheckX >= TriArr[CheckY].size())
		{
			continue;
		}

		if (TriArr[CheckY][CheckX] != 1)
		{
			DFS(CheckX, CheckY);
		}
	}
}

vector<int> solution(int n) 
{
	int AllCount = (n * (n + 1)) / 2;
	TriArr.resize(n);
	for (size_t i = 0; i < TriArr.size(); i++)
	{
		TriArr[i].resize(i + 1, 0);
	}

	DFS(0,0);

    vector<int> answer;
    return answer;
}

int main()
{
	solution(6);

	return 0;
}
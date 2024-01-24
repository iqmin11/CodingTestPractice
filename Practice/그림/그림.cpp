#include <iostream>
#include <vector>
#include <queue>

int Y, X;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

std::vector<std::vector<int>> Paints;
std::priority_queue<int> SizeOfPaint;

int DFS(int _StartX, int _StartY)
{
	Paints[_StartY][_StartX] = 0;
	int result = 1;
	for (size_t i = 0; i < 4; i++)
	{
		int CheckX = _StartX + dx[i];
		int CheckY = _StartY + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= X || CheckY >= Y)
		{
			continue;
		}
		
		if (Paints[CheckY][CheckX] == 0)
		{
			continue;
		}

		result += DFS(CheckX, CheckY);
	}

	return result;
}

int main()
{
	std::cin >> Y >> X;
	Paints.resize(Y);
	for (size_t y = 0; y < Y; ++y)
	{
		Paints[y].resize(X);
		for (size_t x = 0; x < X; ++x)
		{
			std::cin >> Paints[y][x];
		}
	}
	
	for (size_t y = 0; y < Y; y++)
	{
		for (size_t x = 0; x < X; x++)
		{
			if (Paints[y][x] == 0)
			{
				continue;
			}

			SizeOfPaint.push(DFS(x, y));
		}
	}

	std::cout << SizeOfPaint.size() << std::endl;
	if (SizeOfPaint.size() == 0)
	{
		std::cout << 0;
	}
	else
	{
		std::cout << SizeOfPaint.top();
	}
}
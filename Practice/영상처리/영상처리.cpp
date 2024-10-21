//문제 주소 : https://www.acmicpc.net/problem/21938

#include <iostream>
#include <vector>

struct RGB
{
	static int T;

	void CalAvg()
	{
		Avg = (r + g + b) / 3;
	}

	void DecideRendering()
	{
		if (Avg >= static_cast<double>(T))
		{
			FinalRender = true;
		}
	}

	double r = -1;
	double g = -1;
	double b = -1;
	double Avg = -1;
	bool FinalRender = false;
	bool IsVisit = false;
};

std::vector<std::vector<RGB>> Viewport;
int Y, X;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void DFS(std::pair<int, int> CurPos)
{
	Viewport[CurPos.second][CurPos.first].IsVisit = true;

	for (int i = 0; i < 4; i++)
	{
		int CheckX = CurPos.first + dx[i];
		int CheckY = CurPos.second + dy[i];

		if (CheckX < 0 || CheckY < 0 || CheckX >= X || CheckY >= Y)
		{
			continue;
		}

		if (Viewport[CheckY][CheckX].FinalRender == false)
		{
			continue;
		}

		if (Viewport[CheckY][CheckX].IsVisit)
		{
			continue;
		}

		DFS(std::make_pair(CheckX, CheckY));
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> Y >> X;
	Viewport.resize(Y);
	for (int y = 0; y < Y; y++)
	{
		Viewport[y].resize(X);
		for (int x = 0; x < X; x++)
		{
			int r, g, b;
			std::cin >> r >> g >> b;
			Viewport[y][x].r = r;
			Viewport[y][x].g = g;
			Viewport[y][x].b = b;

			Viewport[y][x].CalAvg();
		}
	}

	std::cin >> RGB::T;

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			Viewport[y][x].DecideRendering();
		}
	}

	int Answer = 0;

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (Viewport[y][x].FinalRender == false)
			{
				continue;
			}

			if (Viewport[y][x].IsVisit)
			{
				continue;
			}

			DFS(std::make_pair(x,y));
			Answer++;
		}
	}

	std::cout << Answer;

	return 0;
}

int RGB::T = -1;
	
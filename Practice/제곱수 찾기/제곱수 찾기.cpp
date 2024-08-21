//문제 주소 : https://www.acmicpc.net/problem/1025

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int Y, X;
std::vector<std::string> Grid;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> Y >> X;
	Grid.resize(Y);

	for (int y = 0; y < Y; y++)
	{
		std::cin >> Grid[y];
	}

	int MaxValue = -1;

	if (X == 1 && Y == 1)
	{
		int CheckNum = Grid[0][0] - '0';
		int RootCheck = static_cast<int>(std::sqrt(CheckNum));
		if (RootCheck * RootCheck == CheckNum)
		{
			MaxValue = std::max(CheckNum, MaxValue);
		}
	}

	for (int dy = -Y + 1; dy < Y; dy++)
	{
		for (int dx = -X + 1; dx < X; dx++)
		{
			if (dy == 0 && dx == 0)
			{
				continue;
			}

			for (int ay = 0; ay < Y; ay++)
			{
				for (int ax = 0; ax < X; ax++)
				{
					std::string NumStr;

					int CurX = ax;
					int CurY = ay;

					while (!(CurX >= X || CurY >= Y || CurX < 0 || CurY < 0))
					{
						NumStr += std::to_string(Grid[CurY][CurX] - '0');
						CurX += dx;
						CurY += dy;

						int CheckNum = std::stoi(NumStr);
						int RootCheck = static_cast<int>(std::sqrt(CheckNum));
						if (RootCheck * RootCheck == CheckNum)
						{
							MaxValue = std::max(CheckNum, MaxValue);
						}
					}


				}
			}
		}
	}

	std::cout << MaxValue;

	return 0;
}
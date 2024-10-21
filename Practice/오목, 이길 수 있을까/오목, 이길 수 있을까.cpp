//문제 주소 : https://www.acmicpc.net/problem/16955

#include <iostream>
#include <vector>

std::vector<std::string> Grid;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Grid.resize(10);
	for (int i = 0; i < 10; i++)
	{
		std::cin >> Grid[i];
	}

	int dx[] = { 1, 1, 0, -1 };
	int dy[] = { 0, 1, 1, 1 };

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (Grid[y][x] == 'O')
			{
				continue;
			}

			for (int Dir = 0; Dir < 4; Dir++)
			{
				int DestX = x + 4 * dx[Dir];
				int DestY = y + 4 * dy[Dir];

				if (DestX < 0 || DestY < 0 || DestX >= 10 || DestY >= 10)
				{
					continue;
				}

				int CountX = 0;
				int CountO = 0;
				int CountVoid = 0;

				for (int Dist = 0; Dist <= 4; Dist++)
				{
					int CheckX = x + Dist * dx[Dir];
					int CheckY = y + Dist * dy[Dir];

					if (Grid[CheckY][CheckX] == 'X')
					{
						++CountX;
					}
					else if (Grid[CheckY][CheckX] == 'O')
					{
						++CountO;
					}
					else if (Grid[CheckY][CheckX] == '.')
					{
						++CountVoid;
					}
				}

				if (CountX == 4 && CountVoid == 1)
				{
					std::cout << 1;
					return 0;
				}
			}
		}
	}

	std::cout << 0;
	return 0;
}


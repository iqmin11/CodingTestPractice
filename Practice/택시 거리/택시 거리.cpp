//문제 주소 : https://www.acmicpc.net/problem/17247

#include <iostream>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int Y, X;
	std::cin >> Y >> X;

	std::pair<int, int> Pos[2];

	int CurIndex = 0;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			int temp;
			std::cin >> temp;
			if (temp == 1)
			{
				Pos[CurIndex].first = x;
				Pos[CurIndex++].second = y;
			}
		}
	}

	int Distance = std::abs(Pos[1].first - Pos[0].first) + std::abs(Pos[1].second - Pos[0].second);
	std::cout << Distance;

	return 0;
}
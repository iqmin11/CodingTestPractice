//문제 주소 : https://www.acmicpc.net/problem/16918

#include <iostream>
#include <vector>
#include <queue>

int R, C, N;
std::vector<std::string> Grid;
std::queue<std::vector<std::string>> BombQ;

std::vector<std::string> PutBomb()
{
	std::vector<std::string> Result;
	Result.resize(R);
	for (int y = 0; y < R; y++)
	{
		Result[y].resize(C, '.');
	}

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if (Grid[y][x] == 'O')
			{
				continue;
			}

			Grid[y][x] = 'O';
			Result[y][x] = 'O';
		}
	}

	return Result;
}

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void Explosion()
{
	std::vector<std::string> CurExplosionBomb = std::move(BombQ.front());
	BombQ.pop();

	std::vector<std::string>& NextBomb = BombQ.front();

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if (CurExplosionBomb[y][x] != 'O')
			{
				continue;
			}

			Grid[y][x] = '.';

			for (int Dir = 0; Dir < 4; Dir++)
			{
				int CheckX = x + dx[Dir];
				int CheckY = y + dy[Dir];

				if (CheckX < 0 || CheckY < 0 || CheckX >= C || CheckY >= R)
				{
					continue;
				}

				Grid[CheckY][CheckX] = '.';
				NextBomb[CheckY][CheckX] = '.';
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> R >> C >> N;

	Grid.resize(R);

	for (int y = 0; y < R; y++)
	{
		std::cin >> Grid[y];
	}

	BombQ.push(Grid);
	int Time = 1;
	
	while(Time++ != N)
	{
		if (Time % 2 == 0)
		{
			BombQ.push(PutBomb());
		}
		else
		{
			Explosion();
		}
	}

	for (int y = 0; y < R; y++)
	{
		std::cout << Grid[y] << '\n';
	}

	return 0;
}
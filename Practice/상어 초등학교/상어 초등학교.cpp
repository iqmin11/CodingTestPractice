//巩力 林家 : https://www.acmicpc.net/problem/21608

#include <iostream>
#include <vector>
#include <queue>

int N;
int StudentCount;

struct Tile
{
	std::pair<int, int> Pos;
	int Student = 0; // 0捞搁 后磊府
};

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

std::vector<std::vector<Tile>> Class;
std::vector<int>* Favorit;
std::vector<std::vector<int>> StudentFavoritInfo;

struct Comp
{
	bool operator()(const std::pair<int, int>& Left, const std::pair<int, int>& Right)
	{
		std::vector<int>& FavoritRef = *Favorit;

		int LeftFavoritCount = 0;
		int RightFavoritCount = 0;

		int LeftVacancyCount = 0;
		int RightVacancyCount = 0;

		for (int i = 0; i < 4; i++)
		{
			int CheckLX = Left.first + dx[i];
			int CheckLY = Left.second + dy[i];
			int CheckRX = Right.first + dx[i];
			int CheckRY = Right.second + dy[i];

			if (!(CheckLX < 1 || CheckLY < 1 || CheckLX > N || CheckLY > N))
			{
				for (int j = 0; j < 4; j++)
				{
					if (FavoritRef[j] == Class[CheckLY][CheckLX].Student)
					{
						LeftFavoritCount++;
					}
					else if (Class[CheckLY][CheckLX].Student == 0)
					{
						LeftVacancyCount++;
					}
				}
			}

			if (!(CheckRX < 1 || CheckRY < 1 || CheckRX > N || CheckRY > N))
			{
				for (int j = 0; j < 4; j++)
				{
					if (FavoritRef[j] == Class[CheckRY][CheckRX].Student)
					{
						RightFavoritCount++;
					}
					else if (Class[CheckRY][CheckRX].Student == 0)
					{
						RightVacancyCount++;
					}
				}
			}
		}

		if (LeftFavoritCount < RightFavoritCount)
		{
			return true;
		}
		else if (LeftFavoritCount == RightFavoritCount)
		{
			if (LeftVacancyCount < RightVacancyCount)
			{
				return true;
			}
			else if (LeftVacancyCount == RightVacancyCount)
			{
				return Left > Right;
			}
		}

		return false;
	}
};

int main()
{
	std::cin >> N;
	StudentCount = N * N;
	Class.resize(N + 1);
	for (int i = 0; i <= N; i++)
	{
		Class[i].resize(N + 1);
	}

	StudentFavoritInfo.resize(StudentCount + 1);
	for (int i = 0; i < StudentCount; i++)
	{
		int CurStudent;
		std::cin >> CurStudent;
		StudentFavoritInfo[CurStudent].resize(4);
		for (int j = 0; j < 4; j++)
		{
			std::cin >> StudentFavoritInfo[CurStudent][j];
		}

		Favorit = &StudentFavoritInfo[CurStudent];
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comp> pq;

		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (Class[y][x].Student != 0)
				{
					continue;
				}

				pq.push(std::make_pair(x, y));
			}
		}

		std::pair<int, int> Decision = pq.top();
		Class[Decision.second][Decision.first].Pos = Decision;
		Class[Decision.second][Decision.first].Student = CurStudent;
	}

	int Happy = 0;
	int HappyScoreTable[5] = { 0,1,10,100,1000 };
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			int FavoritCount = 0;

			for (int Dir = 0; Dir < 4; Dir++)
			{
				int CheckX = x + dx[Dir];
				int CheckY = y + dy[Dir];

				if (CheckX < 1 || CheckY < 1 || CheckX > N || CheckY > N)
				{
					continue;
				}

				for (int i = 0; i < 4; i++)
				{
					if (StudentFavoritInfo[Class[y][x].Student][i] == Class[CheckY][CheckX].Student)
					{
						FavoritCount++;
					}
				}
			}

			Happy += HappyScoreTable[FavoritCount];
		}
	}

	std::cout << Happy;
	return 0;
}
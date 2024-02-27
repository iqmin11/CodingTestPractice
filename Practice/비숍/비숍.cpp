#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> Grid;
std::vector<std::vector<bool>> IsVisit;
std::vector<std::vector<int>> Check;

int Diagonal_dx[] = {1, 1, -1, -1};
int Diagonal_dy[] = {1, -1, 1, -1};

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int Count = 0;
int MaxCount = INT32_MIN;

void DFS(int StartX, int StartY)
{
	++Count;
	IsVisit[StartY][StartX] = true;

	//놓은곳 기준으로 말을 못 놓는 곳을 설정
	Check[StartY][StartX] += 1;
	for (int i = 0; i < 4; i++)
	{
		int Scalar = 1;
		while (true)
		{
			int CheckX = StartX + (Diagonal_dx[i] * Scalar);
			int CheckY = StartY + (Diagonal_dy[i] * Scalar);

			if (CheckX < 0 || CheckY < 0 || CheckX >= N || CheckY >= N)
			{
				break;
			}

			Scalar++;
			Check[CheckY][CheckX] += 1;
		}
	}

	//가로세로만 체크
	for (int i = 0; i < 4; i++)
	{
		int Scalar = 1;
		while (true)
		{
			int CheckX = StartX + (dx[i] * Scalar);
			int CheckY = StartY + (dy[i] * Scalar);

			if (CheckX < 0 || CheckY < 0 || CheckX >= N || CheckY >= N)
			{
				break;
			}

			Scalar++;

			if (IsVisit[CheckY][CheckX] == true)
			{
				continue;
			}

			if (Grid[CheckY][CheckX] == 0)
			{
				continue;
			}

			if (Check[CheckY][CheckX] != 0)
			{
				continue;
			}

			DFS(CheckX, CheckY);
		}
	}

	//더블 체크
	for (int CheckY = 0; CheckY < N; CheckY++)
	{
		for (int CheckX = 0; CheckX < N; CheckX++)
		{
			if (IsVisit[(N - 1) - CheckY][(N - 1) - CheckX] == true)
			{
				continue;
			}

			if (Grid[(N - 1) - CheckY][(N - 1) - CheckX] == 0)
			{
				continue;
			}

			if (Check[(N - 1) - CheckY][(N - 1) - CheckX] != 0)
			{
				continue;
			}

			DFS((N - 1) - CheckX, (N - 1) - CheckY);
		}
	}
}

int main()	
{
	std::cin >> N;

	Grid.resize(N);
	IsVisit.resize(N);
	Check.resize(N);
	for (int i = 0; i < N; i++)
	{
		Grid[i].resize(N);
		IsVisit[i].resize(N, false);
		Check[i].resize(N, 0);
		for (int j = 0; j < N; j++)
		{
			std::cin >> Grid[i][j];
		}
	}

	std::vector<std::vector<bool>> IsVisitBuffer = IsVisit;
	std::vector<std::vector<int>> CheckBuffer = Check;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (Grid[y][x] == 0)
			{
				continue;
			}

			DFS(x, y);
			MaxCount = std::max(MaxCount, Count);

			IsVisit = IsVisitBuffer;
			Check = CheckBuffer;
			Count = 0;
		}
	}

	std::cout << MaxCount;
}
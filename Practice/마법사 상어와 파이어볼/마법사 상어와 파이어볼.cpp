//문제 주소 : https://www.acmicpc.net/problem/20056

#include <iostream>
#include <list>
#include <vector>

int N, M, K;
int NN;

int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

struct FireBall
{
	void Move()
	{
		Pos.first = ((Pos.first + dx[Dir] * Speed) + NN) % N;
		Pos.second = ((Pos.second + dy[Dir] * Speed) + NN) % N;
	}

	std::pair<int, int> Pos;
	int Mass = -1;
	int Dir = -1;
	int Speed = -1;
};

struct Tile
{
	void SumAndDiv()
	{
		int Size = FireBalls.size();
		
		if (Size <= 1)
		{
			return;
		}

		int SumMass = 0;
		int SumSpeed = 0;
		int PrevDir = FireBalls.begin()->Dir % 2;
		bool IsSame = true;
		std::pair<int, int> CurPos = FireBalls.begin()->Pos;

		//합친다
		for (auto CurIter = FireBalls.begin(); CurIter != FireBalls.end(); ++CurIter)
		{
			SumMass += CurIter->Mass;
			SumSpeed += CurIter->Speed;
			
			if (IsSame == false)
			{
				continue;
			}

			int CurDir = CurIter->Dir % 2;
			if (CurDir != PrevDir)
			{
				IsSame = false;
			}
			PrevDir = CurDir;
		}

		FireBalls.clear();

		if (SumMass / 5 == 0)
		{
			return;
		}
		
		int Weight = static_cast<int>(!IsSame);
		//나눈다
		for (size_t i = 0; i < 4; i++)
		{
			FireBall DivFireBall;
			DivFireBall.Pos = CurPos;
			DivFireBall.Mass = SumMass / 5;
			DivFireBall.Speed = SumSpeed / Size;
			DivFireBall.Dir = 2 * i + Weight;
			FireBalls.push_back(DivFireBall);
		}
	}

	std::list<FireBall> FireBalls;
};

std::vector<std::vector<Tile>> GridFrontBuffer;
std::vector<std::vector<Tile>> GridBackBuffer;

void DebugRenderer(int Info)
{
	std::cout << "////////////////////////" << std::endl;

	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < N; x++)
		{
			
			std::cout << "[";
			for (auto& i : GridBackBuffer[y][x].FireBalls)
			{
				switch (Info)
				{
				case 0:
					std::cout << "(" << i.Mass << ")";
					break;
				case 1:
					std::cout << "(" << i.Speed << "," <<i.Dir << ")";
					break;
				default:
					break;
				}
			}
			std::cout << "]";
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M >> K;

	NN = N;
	while (NN < 1000)
	{
		NN *= NN;
	}

	GridFrontBuffer.resize(N);
	for (int i = 0; i < N; i++)
	{
		GridFrontBuffer[i].resize(N);
	}

	//Init
	for (int i = 0; i < M; i++)
	{
		int y, x, m, s, d;
		std::cin >> y >> x >> m >> s >> d;
		FireBall CurFireBall;
		CurFireBall.Pos = std::make_pair(x - 1,y - 1);
		CurFireBall.Mass = m;
		CurFireBall.Speed = s;
		CurFireBall.Dir = d;

		GridFrontBuffer[CurFireBall.Pos.second][CurFireBall.Pos.first].FireBalls.push_back(CurFireBall);
	}

	GridBackBuffer.resize(N);

	//MoveCmd
	while (K-- > 0)
	{
		for (int y = 0; y < N; y++)
		{
			GridBackBuffer[y].clear();
			GridBackBuffer[y].resize(N);
		}

		//TODO: 이동한다
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (GridFrontBuffer[y][x].FireBalls.empty())
				{
					continue;
				}

				for (auto CurIter = GridFrontBuffer[y][x].FireBalls.begin(); CurIter != GridFrontBuffer[y][x].FireBalls.end(); ++CurIter)
				{
					CurIter->Move();
					GridBackBuffer[CurIter->Pos.second][CurIter->Pos.first].FireBalls.push_back(std::move(*CurIter));
				}
			}
		}

		//TODO: 합치고 나눈다
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				GridBackBuffer[y][x].SumAndDiv();
			}
		}
		
		std::swap(GridFrontBuffer, GridBackBuffer);
	}

	int Answer = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			for (auto CurIter = GridFrontBuffer[y][x].FireBalls.begin(); CurIter != GridFrontBuffer[y][x].FireBalls.end(); ++CurIter)
			{
				Answer += CurIter->Mass;
			}
		}
	}

	std::cout << Answer;

	return 0;
}
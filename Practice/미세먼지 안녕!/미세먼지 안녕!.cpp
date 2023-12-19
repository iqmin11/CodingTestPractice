#include <iostream>
#include <vector>
#include <map>
#include <queue>

std::vector<std::vector<int>> DustMap;
std::map<std::pair<int, int>, int> Dusts; //위치와 강도
std::pair<int, int> AirUp = std::pair<int, int>(); //위쪽 청정기
std::pair<int, int> AirDown = std::pair<int, int>(); //아래쪽 청정기

std::map<std::pair<int, int>, int> Wind; //좌표와 방향;

enum Wind
{
	E,
	W,
	S,
	N
};

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

std::vector<std::vector<int>> DoubleBuffer;
int R, C, T;

void DebugScreen() //디버깅 용
{
	std::cout << "/////////////////////////////////////////////" << std::endl;
	
	for (size_t i = 0; i < R; i++)
	{
		for (size_t j = 0; j < C; j++)
		{
			std::cout << DustMap[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "/////////////////////////////////////////////" << std::endl;
}

void Init()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
}

int main()
{
	Init();

	std::cin >> R >> C >> T;

	DustMap.resize(R);
	DoubleBuffer.resize(R);

	for (size_t i = 0; i < R; i++)
	{
		DustMap[i].resize(C);
		DoubleBuffer[i].resize(C, 0);
		for (size_t j = 0; j < C; j++)
		{
			int Input;
			std::cin >> Input;

			if (Input == -1) //공기청정기 위치
			{
				if (AirUp == std::pair<int, int>())
				{
					AirUp = std::make_pair(j, i);

					for (size_t e = 1; e < C - 1; e++)
					{
						Wind.insert(std::make_pair(std::make_pair(e, i), Wind::E));
					}
					
					for (size_t n = 1; n <= i; n++)
					{
						Wind.insert(std::make_pair(std::make_pair(C-1, n), Wind::N));
					}

					for (size_t w = 1; w < C; w++)
					{
						Wind.insert(std::make_pair(std::make_pair(w, 0), Wind::W));
					}

					for (size_t s = 0; s <= i - 1; s++)
					{
						Wind.insert(std::make_pair(std::make_pair(0, s), Wind::S));
					}
				}
				else
				{
					AirDown = std::make_pair(j, i);

					for (size_t e = 1; e < C - 1; e++)
					{
						Wind.insert(std::make_pair(std::make_pair(e, i), Wind::E));
					}

					for (size_t n = i + 1; n <= R - 1; n++)
					{
						Wind.insert(std::make_pair(std::make_pair(0, n), Wind::N));
					}

					for (size_t w = 1; w <= C - 1; w++)
					{
						Wind.insert(std::make_pair(std::make_pair(w, R - 1), Wind::W));
					}

					for (size_t s = i; s < R - 1; s++)
					{
						Wind.insert(std::make_pair(std::make_pair(C - 1, s), Wind::S));
					}
				}
			}
			else if (Input != 0) //미세먼지 스타트 위치
			{
				Dusts.insert(std::make_pair(std::make_pair(j, i), Input));
			}

			DustMap[i][j] = Input;
		}
	}

	while (T-- != 0) //몇프레임 돌아야 하니
	{
		for (auto& Dust : Dusts) //먼지 위치 돌면서
		{
			int CurPosX = Dust.first.first;
			int CurPosY = Dust.first.second;
			int Count = 0;

			for (size_t i = 0; i < 4; i++)
			{
				int CheckX = CurPosX + dx[i];
				int CheckY = CurPosY + dy[i];

				if (CheckX < 0 || CheckY < 0 || CheckX >= C || CheckY >= R || DustMap[CheckY][CheckX] == -1) //확산 위치 확인
				{
					continue;
				}
				++Count;
				DoubleBuffer[CheckY][CheckX] += Dust.second / 5; //확산 되면 기록(더블버퍼에)
			}
			DustMap[CurPosY][CurPosX] -= ((Dust.second / 5) * Count); //확산 후 원래위치 감소(본래 맵에)
		}

		for (size_t i = 0; i < R; i++) //더블버퍼 + 본래 맵 하고 더블버퍼 0으로 초기화 (바람 영향 기록 준비)
		{
			for (size_t j = 0; j < C; j++)
			{
				DustMap[i][j] = DustMap[i][j] + DoubleBuffer[i][j];
				DoubleBuffer[i][j] = 0;
			}
		}

		for (auto& WindInfo : Wind) //바람 돌면서
		{
			std::pair<int, int> WindPos = WindInfo.first;
			std::pair<int, int> NextPos = std::pair<int, int>();
			switch (WindInfo.second) //바람영향받은 NextPos 기록
			{
			case Wind::E:
				NextPos = { WindPos.first + 1 , WindPos.second };
				break;
			case Wind::W:
				NextPos = { WindPos.first - 1 , WindPos.second };
				break;
			case Wind::S:
				NextPos = { WindPos.first , WindPos.second + 1 };
				break;
			case Wind::N:
				NextPos = { WindPos.first , WindPos.second - 1 };
				break;
			default:
				break;
			}

			if (AirUp == NextPos || AirDown == NextPos) //거기가 청정기이면 작업 안함
			{
				continue;
			}

			DoubleBuffer[NextPos.second][NextPos.first] = DustMap[WindPos.second][WindPos.first]; //본맵의 먼지들, 바람영향 받은 버전으로 더블버퍼에 기록
		}

		for (auto& WindInfo : Wind)
		{
			std::pair<int, int> WindPos = WindInfo.first;
			DustMap[WindPos.second][WindPos.first] = DoubleBuffer[WindPos.second][WindPos.first]; //그걸 다시 본 맵에 기록하고
			DoubleBuffer[WindPos.second][WindPos.first] = 0; //더블버퍼 초기화
		}

		Dusts.clear(); //먼지 기록 초기화

		for (size_t i = 0; i < R; i++)
		{
			for (size_t j = 0; j < C; j++)
			{
				if (DustMap[i][j] != 0 && DustMap[i][j] != -1)
				{
					Dusts.insert(std::make_pair(std::make_pair(j, i), DustMap[i][j])); //본맵 돌면서 먼지 기록
				}
			}
		}
	}

	int Answer = 0;

	for (auto& i : Dusts)
	{
		Answer += i.second; 
	}

	std::cout << Answer;

	return 0;
}
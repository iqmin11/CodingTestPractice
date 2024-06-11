//���� �ּ� : https://www.acmicpc.net/problem/15683

#include <iostream>
#include <vector>
#include <map>

//������ ���� ������ ��� ����� ���� �� üũ
//�����ִ� ī�޶��� ������ �����ָ鼭 ���� üũ

struct Camera
{
	Camera(int C)
		: Case(C) {}

	int Case = 0; //1, 2, 3, 4, 5
	int Dir = -1; //0, 1, 2, 3
};

int N, M;
std::vector<std::vector<int>> Grid;
std::map<std::pair<int, int>, Camera> Cameras;

int dx[] = { 1, 0 ,-1, 0 };
int dy[] = { 0, 1 ,0, -1 };

int TileCheck()
{
	std::vector<std::vector<int>> GridBuffer = Grid;
	int Count = 0;

	//ī�޶� ����
	for (auto Cam : Cameras)
	{
		bool IsCollision[] = { false, false, false, false };
		std::pair<int, int> CamPos = Cam.first;
		int CamCase = Cam.second.Case;
		int CamDir = Cam.second.Dir;
		int NextDir = (CamDir + 1) % 4;
		int JumpDir = (CamDir + 2) % 4;
		int LastDir = (CamDir + 3) % 4;

		//üũ ����
		int Dist = 0;

		int BreakCount = 0;
		if (CamCase < 3)
		{
			BreakCount = CamCase;
		}
		else
		{
			BreakCount = CamCase - 1;
		}

		//��ĭ�� �÷����� üũ
		while (++Dist)
		{
			//���ð� �Ұ����ϸ� Ż��
			if (BreakCount == 0)
			{
				break;
			}

			for (int i = CamDir; i < CamDir + 4; i++)
			{
				int CheckDir = i % 4;

				if (CamCase == 1 && CamDir != CheckDir)
				{
					//���۹��⸸
					continue;
				}
				else if (CamCase == 2 && (CamDir != CheckDir && JumpDir != CheckDir))
				{
					//���۹���, ��ĭ �� ����
					continue;
				}
				else if (CamCase == 3 && (CamDir != CheckDir && NextDir != CheckDir))
				{
					//���۹���, ��������
					continue;
				}
				else if (CamCase == 4 && (CamDir != CheckDir && NextDir != CheckDir && JumpDir != CheckDir))
				{
					//����
					continue;
				}

				//��������
				if (IsCollision[CheckDir])
				{
					continue;
				}

				int CheckX = CamPos.first + dx[CheckDir] * Dist;
				int CheckY = CamPos.second + dy[CheckDir] * Dist;

				if (CheckX < 0 || CheckY < 0 || CheckX >= M || CheckY >= N)
				{
					IsCollision[CheckDir] = true;
					--BreakCount;
					continue;
				}

				if (GridBuffer[CheckY][CheckX] == 6)
				{
					IsCollision[CheckDir] = true;
					--BreakCount;
					continue;
				}

				if (GridBuffer[CheckY][CheckX] != 0)
				{
					continue;
				}

				//����
				GridBuffer[CheckY][CheckX] = 9;
				Count++;
			}
		}
	}

	return Count;
}

int WatchMaxCount = INT32_MIN;

//ī�޶��� ������ ���Ѵ�
void BT(std::map<std::pair<int, int>, Camera>::iterator CurIter)
{
	if (Cameras.end() == CurIter)
	{
		//������ ����
		WatchMaxCount = std::max(WatchMaxCount, TileCheck());
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		CurIter->second.Dir = i;
		BT(std::next(CurIter));
	}
}

int main()
{
	//Init
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//Input
	std::cin >> N >> M;

	int TileCount = N * M;

	Grid.resize(N);
	for (int y = 0; y < N; y++)
	{
		Grid[y].resize(M);
		for (int x = 0; x < M; x++)
		{
			std::cin >> Grid[y][x];

			if (Grid[y][x] != 0)
			{
				--TileCount;
				if (Grid[y][x] != 6)
				{
					Cameras.insert(std::make_pair(std::make_pair(x, y), Camera(Grid[y][x])));
				}
			}
		}
	}

	//Sol
	//1. ī�޶��� ������ ���Ѵ�(BT)
	BT(Cameras.begin());

	//Output
	std::cout << TileCount - WatchMaxCount;

	return 0;
}
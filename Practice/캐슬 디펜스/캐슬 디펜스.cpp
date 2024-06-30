//문제 주소 : https://www.acmicpc.net/problem/17135

#include <iostream>
#include <vector>
#include <deque>
#include <functional>
#include <algorithm>

int Y, X, D;
int EnemyCount = 0;

struct EnemyStruct
{
	EnemyStruct(const std::pair<int, int>& _Pos)
		: Pos(_Pos)
	{

	}

	std::pair<int, int> Pos;
	bool IsDeath = false;
};

std::deque<int> ArcherXPos;
std::vector<EnemyStruct> Enemy;
std::vector<std::pair<int, int>> EnemyInit;

void BT(int CurXIndex, std::function<void()> Simulation)
{
	if (ArcherXPos.size() == 3)
	{
		Simulation();
		return;
	}

	for (int i = CurXIndex; i < X; i++)
	{
		ArcherXPos.push_back(i);
		BT(i + 1, Simulation);
		ArcherXPos.pop_back();
	}
}

int Attack()
{
	int Kill = 0;

	for (int i = 0; i < ArcherXPos.size(); i++)
	{
		int CurArcherX = ArcherXPos[i];
		int CurArcherY = Y;

		//아쳐와의 거리 우선순위 정렬. 거리, 왼쪽
		std::sort(Enemy.begin(), Enemy.end(), [=](const EnemyStruct& Left, const EnemyStruct& Right)
			{
				int LeftDist = std::abs(CurArcherX - Left.Pos.first) + std::abs(CurArcherY - Left.Pos.second);
				int RightDist = std::abs(CurArcherX - Right.Pos.first) + std::abs(CurArcherY - Right.Pos.second);

				if (LeftDist == RightDist)
				{
					return Left.Pos.first < Right.Pos.first;
				}

				return LeftDist < RightDist;
			});
		
		//우선순위가 가장 높은 적
		int CurEnemyX = Enemy.front().Pos.first;
		int CurEnemyY = Enemy.front().Pos.second;
		int Dist = std::abs(CurArcherX - CurEnemyX) + std::abs(CurArcherY - CurEnemyY);

		if (Dist > D)
		{
			continue;
		}

		if (!Enemy.front().IsDeath)
		{
			Enemy.front().IsDeath = true;
			Kill++;
		}
	}

	for (std::vector<EnemyStruct>::iterator CurEnemy = Enemy.begin(); CurEnemy != Enemy.end(); )
	{
		if (CurEnemy->IsDeath)
		{
			CurEnemy = Enemy.erase(CurEnemy);
		}
		else
		{
			++CurEnemy;
		}
	}

	return Kill;
}

void EnemyMove()
{
	for (std::vector<EnemyStruct>::iterator CurEnemy = Enemy.begin(); CurEnemy != Enemy.end(); )
	{
		int& YRef = CurEnemy->Pos.second;
		if (++YRef >= Y)
		{
			CurEnemy = Enemy.erase(CurEnemy);
		}
		else
		{
			++CurEnemy;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> Y >> X >> D;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			int temp;
			std::cin >> temp;
			if (temp == 1)
			{
				EnemyInit.push_back(std::make_pair(x, y));
			}
		}
	}

	int MaxScore = INT32_MIN;
	
	//0 ~ X - 1에서 세 궁수의 위치를 정함, 궁수의 Y좌표는 Y로 고정
	BT(0, [&]()
		{
			//Init
			Enemy.clear();

			for (int i = 0; i < EnemyInit.size(); i++)
			{
				Enemy.push_back(EnemyStruct(EnemyInit[i]));
			}

			int Score = 0;

			//Simulation
			while (!Enemy.empty())
			{
				//궁수가 적을 공격
				Score += Attack();

				//적이 이동
				EnemyMove();
			}

			MaxScore = std::max(MaxScore, Score);
		});

	std::cout << MaxScore;
	
	return 0;
}
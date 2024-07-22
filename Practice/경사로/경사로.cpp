//문제 주소 : https://www.acmicpc.net/problem/14890

#include <iostream>
#include <vector>
#include <cmath>

int N, M;
std::vector<std::vector<int>> Grid;

bool IsPass(const std::vector<int>& Path)
{
	int PrevCheck = 0;
	int Continuous = 1;

	std::vector<bool> IsSlope;
	IsSlope.resize(Path.size(), false);

	for (int CurCheck = 1; CurCheck < Path.size(); CurCheck++)
	{
		//높이가 2이상 차이날 경우
		int Differ = Path[CurCheck] - Path[PrevCheck];
		int DifferSize = std::abs(Differ);
		if (DifferSize > 1)
		{
			return false;
		}
		else if(DifferSize == 1)
		{
			//경사로를 놓을 공간이 부족한 경우
			if (Differ > 0)
			{
				//오르막
				//왼쪽체크
				if (Continuous < M)
				{
					return false;
				}

				for (int j = CurCheck - M; j < CurCheck; j++)
				{
					//경사로가 이미 있는 경우
					if (IsSlope[j])
					{
						return false;
					}

					IsSlope[j] = true;
				}
			}
			else if (Differ < 0)
			{
				//내리막
				//오른쪽체크
				int CurHight = Path[CurCheck];

				if (CurCheck + M > Path.size())
				{
					return false;
				}

				for (int NextCheck = CurCheck; NextCheck < CurCheck + M; NextCheck++)
				{
					if (CurHight != Path[NextCheck])
					{
						return false;
					}

					IsSlope[NextCheck] = true;
				}

				CurCheck += M - 1;
			}

			Continuous = 1;
		}
		else
		{
			++Continuous;
		}

		PrevCheck = CurCheck;
	}

	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	Grid.resize(N);
	for (int i = 0; i < N; i++)
	{
		Grid[i].resize(N);
		for (int j = 0; j < N; j++)
		{
			std::cin >> Grid[i][j];
		}
	}

	int Answer = 0;

	for (int i = 0; i < N; i++)
	{
		if (IsPass(Grid[i]))
		{
			++Answer;
		}

		std::vector<int> temp;
		temp.resize(N);
		for (int j = 0; j < N; j++)
		{
			temp[j] = Grid[j][i];
		}

		if (IsPass(std::move(temp)))
		{
			++Answer;
		}
	}
	
	std::cout << Answer;

	return 0;
}
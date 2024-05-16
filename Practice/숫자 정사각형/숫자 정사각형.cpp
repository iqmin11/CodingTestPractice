//문제 주소 : https://www.acmicpc.net/problem/1051

#include <iostream>
#include <vector>

//왼쪽 위 점으로 부터 만들수 있는 가장 큰 정사각형 만들기
//(x,y) (x + a, y) (x, y + a) (x + a, y + a) 

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;

	std::cin >> N >> M;

	std::vector<std::string> Grid;
	Grid.resize(N);

	for (int y = 0; y < N; y++)
	{
		std::cin >> Grid[y];
	}

	int dx[3] = { 1, 0, 1 };
	int dy[3] = { 0, 1, 1 };

	int MaxAnswer = INT32_MIN;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			//각 출발지점마다 정사각형 검사 하기
			int a = -1; //변의 길이
			bool IsBreak = false;

			while (!IsBreak)
			{
				++a;
				bool IsPossible = true; // 쿼리에 부합하는가
				for (int i = 0; i < 3; i++)
				{
					int CheckX = x + (dx[i] * a);
					int CheckY = y + (dy[i] * a);

					if (CheckX >= M || CheckY >= N)
					{
						//정사각형을 만들 수 없음
						//다음 스타트 지점으로 넘어가야함
						IsBreak = true;
						IsPossible = false;
						break;
					}

					if (Grid[y][x] != Grid[CheckY][CheckX])
					{
						//쿼리에 부합하지 않음
						//더 큰 정사각형을 만들어 봐야함
						IsPossible = false;
						break;
					}
				}

				//변의 길이 맥스 값 갱신
				if (IsPossible) //쿼리에 부합하면
				{
					MaxAnswer = std::max(MaxAnswer, a);
				}
			}
		}
	}

	std::cout << (MaxAnswer + 1) * (MaxAnswer + 1);

	return 0;
}
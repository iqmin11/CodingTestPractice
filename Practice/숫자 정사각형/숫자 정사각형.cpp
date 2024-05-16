//���� �ּ� : https://www.acmicpc.net/problem/1051

#include <iostream>
#include <vector>

//���� �� ������ ���� ����� �ִ� ���� ū ���簢�� �����
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
			//�� ����������� ���簢�� �˻� �ϱ�
			int a = -1; //���� ����
			bool IsBreak = false;

			while (!IsBreak)
			{
				++a;
				bool IsPossible = true; // ������ �����ϴ°�
				for (int i = 0; i < 3; i++)
				{
					int CheckX = x + (dx[i] * a);
					int CheckY = y + (dy[i] * a);

					if (CheckX >= M || CheckY >= N)
					{
						//���簢���� ���� �� ����
						//���� ��ŸƮ �������� �Ѿ����
						IsBreak = true;
						IsPossible = false;
						break;
					}

					if (Grid[y][x] != Grid[CheckY][CheckX])
					{
						//������ �������� ����
						//�� ū ���簢���� ����� ������
						IsPossible = false;
						break;
					}
				}

				//���� ���� �ƽ� �� ����
				if (IsPossible) //������ �����ϸ�
				{
					MaxAnswer = std::max(MaxAnswer, a);
				}
			}
		}
	}

	std::cout << (MaxAnswer + 1) * (MaxAnswer + 1);

	return 0;
}
//���� �ּ� : https://www.acmicpc.net/problem/10942

#include <iostream>
#include <vector>

bool DP[2000][2000]; // DP[a][b] = Arr�� a��° �׿��� b��°�ױ����� �Ӹ�����ΰ�?
int N, M;
std::vector<int> Arr;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	Arr.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}

	std::cin >> M;
	
	//���� 1¥�� �Ӹ���� �˻�
	for (int i = 0; i < N; i++)
	{
		DP[i][i] = true;
	}

	//���� 2¥�� �Ӹ���� �˻�
	for (int i = 0; i < N - 1; i++)
	{
		if (Arr[i] == Arr[i + 1])
		{
			DP[i][i + 1] = true;
		}
		else
		{
			DP[i][i + 1] = false;
		}
	}

	//���� 3�̻� �Ӹ���� �˻�
	for (int Length = 3; Length <= N; Length++)
	{
		for (int Start = 0; Start < N - (Length - 1); Start++)
		{
			int End = Start + (Length - 1);

			if (Arr[Start] == Arr[End] && DP[Start + 1][End - 1])
			{
				DP[Start][End] = true;
			}
			else
			{
				DP[Start][End] = false;
			}
		}
	}

	std::vector<bool> Answer;

	for (int i = 0; i < M; i++)
	{
		int Start, End;
		std::cin >> Start >> End;

		Answer.push_back(DP[Start - 1][End - 1]);
	}

	for (auto i : Answer)
	{
		std::cout << i << '\n';
	}

	return 0;
}
//���� �ּ� : https://www.acmicpc.net/problem/2502

#include <iostream>

int DP[31][2]; 
// DP[a][0]  = a��° ��, ù°�� �� ���� ������ �����ŭ �����?
// DP[a][1]  = a��° ��, ��°�� �� ���� ������ �����ŭ �����?


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int D, K;
	std::cin >> D >> K;

	DP[1][0] = 1;
	DP[1][1] = 0;
	DP[2][0] = 0;
	DP[2][1] = 1;

	for (int i = 3; i <= D; i++)
	{
		DP[i][0] = DP[i - 1][0] + DP[i - 2][0];
		DP[i][1] = DP[i - 1][1] + DP[i - 2][1];
	}

	for (int i = 1; i <= K; i++)
	{
		//i = ù°���� �� ���� ����
		int Give = i * DP[D][0];
		int Left = K - Give;

		if (Left % DP[D][1] == 0)
		{
			std::cout << i << std::endl;
			std::cout << Left / DP[D][1] << std::endl;
			return 0;
		}
	}

	return 0;
}
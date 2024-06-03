//���� �ּ� : https://www.acmicpc.net/problem/10844

#include <iostream>
#include <numeric>

//int DP[101] = {}; // DP[a] = n ���� a�� ��ܼ��� n��
//���� a�� ��ܼ��� ���� a-1�� ��ܼ��� �������
//�⺻������ ���� �ö󰡴� ��ܼ� �ϳ�, ������ �������� ��ܼ� �ϳ��� �ֱ⶧���� a * 2���� ��ܼ��� �����������
//��ܼ��� 0�̳� 9�� �����ٸ� 1���� ��ܼ��ۿ� �Ļ���ų �� ����. �װ� ��� �����ϳİ� ������ ��
//�׷� �̷��� �غ���

int DP[101][10]; //DP[a][b] = n // b�� ������ ���� a�� ��ܼ��� n��

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 1; i <= 9; i++)
	{
		DP[1][i] = 1;
	}

	int Mod = 1000000000;

	for (int i = 2; i <= 100; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) 
			{
				DP[i][j] = DP[i - 1][j + 1] % Mod;
			}
			else if (j == 9)
			{
				DP[i][j] = DP[i - 1][j - 1] % Mod;
			}
			else
			{
				DP[i][j] = (DP[i - 1][j - 1] % Mod + DP[i - 1][j + 1] % Mod) % Mod;
			}
		}
	}

	int Answer = 0;
	for (int i = 0; i < 10; i++)
	{
		Answer += DP[N][i] % Mod;
		Answer %= Mod;
	}

	std::cout << Answer;

	return 0;
}
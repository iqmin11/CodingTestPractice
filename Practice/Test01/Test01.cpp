//���� �ּ� : 

#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int M = 2;
	int N = 10;
	std::vector<int> DiceCase = { 2,5}; //�ֻ��� ���� ������ N�� ����� ���

	std::vector<int> DP(N + 1);
	DP[0] = 1;

	//DP[a] = �ֻ��� ���� ���ؼ� a�� ������ ����Ǽ�
	//DP[a]�� ������ ���ü� �ִ� ������ DP[b]���� ����Ǽ��� ��
	//b�� a - �ֻ��� ������ �̷���� ������
	//��� ����Ǽ��� ���ϸ� DP[a]�� ����.
	//DP[0] = 1�� �ǹ̴� �ᱹ ã�� ���� a�� �ֻ��������� ������, 1�� �����ֱ� ���� ���ΰ�

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i < DiceCase[j])
			{
				continue;
			}

			DP[i] += DP[i - DiceCase[j]];
		}
	}

	std::cout << DP[N];
	return 0;
}
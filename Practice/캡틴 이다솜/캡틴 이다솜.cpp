//���� �ּ� : https://www.acmicpc.net/problem/1660

#include <iostream>
#include <vector>

int N;
std::vector<int> Case;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	
	Case.reserve(122);

	Case.push_back(0);
	int i = 1;
	while (true)
	{
		int temp = 0;
		for (int j = 1; j <= i; j++)
		{
			temp += j * (i - j + 1);
		}

		if (temp > N)
		{
			break;
		}

		Case.push_back(temp);
		i++;
	}
	
	//DP[i] // i�� ����� �ִ� �ּ�
	std::vector<int> DP;
	DP.resize(300001, INT32_MAX);
	DP[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		//i���� ���� Case�� üũ �ϸ鼭 �ּҰ� ����

		for (int j = 1; j < Case.size(); j++)
		{
			if (Case[j] > i)
			{
				break;
			}

			DP[i] = std::min(DP[i], DP[i - Case[j]] + 1);
		}
	}

	std::cout << DP[N];

	return 0;
}
//���� �ּ� : https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>

int DP[101][100001] = {}; // DP[i][w]�ִ� ���԰� w�� ���濡�� i��° ���Ǳ����� �Ǵ� ���� �� �ִ� ��ġ

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;
	std::cin >> N >> K;

	std::vector<std::pair<int, int>> Load;
	Load.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		std::cin >> Load[i].first >> Load[i].second;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int w = 1; w <= K; w++)
		{
			if (Load[i].first > w)
			{
				DP[i][w] = DP[i - 1][w];
			}
			else
			{
				DP[i][w] = std::max(DP[i - 1][w], DP[i - 1][w - Load[i].first] + Load[i].second);
			}
		}
	}

	std::cout << DP[N][K];

	return 0;
}
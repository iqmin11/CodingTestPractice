//���� �ּ� : https://www.acmicpc.net/problem/12015

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<int> Arr(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}

	std::vector<int> DP; // DP[i] ���� i�� �����ϴ� �κм����� ������ ���� �� ���� ���� ��;

	for (int i = 0; i < N; i++)
	{
		if (DP.empty() || Arr[i] > DP.back())
		{
			DP.push_back(Arr[i]);
		}
		else
		{
			auto FindIter = std::lower_bound(DP.begin(), DP.end(), Arr[i]);
			*FindIter = Arr[i];
		}
	}

	std::cout << DP.size();

	return 0;
}
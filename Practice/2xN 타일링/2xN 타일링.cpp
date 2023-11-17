#include <iostream>

int DP[100001];

int main()
{
	int N;
	std::cin >> N;

	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;
	//DP[3] = 3;
	//DP[4] = 5;


	for (int i = 3; i <= N; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
		DP[i] = DP[i] % 10007;
	}

	std::cout << DP[N];

	return 0;
}
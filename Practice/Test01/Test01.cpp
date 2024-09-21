//문제 주소 : 

#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int M = 2;
	int N = 10;
	std::vector<int> DiceCase = { 2,5}; //주사위 눈의 합으로 N을 만드는 방법

	std::vector<int> DP(N + 1);
	DP[0] = 1;

	//DP[a] = 주사위 눈을 더해서 a가 나오는 경우의수
	//DP[a]는 직전에 나올수 있는 숫자인 DP[b]들의 경우의수의 합
	//b는 a - 주사위 눈으로 이루어져 있을것
	//모든 경우의수를 합하면 DP[a]가 나옴.
	//DP[0] = 1의 의미는 결국 찾는 값인 a가 주사위눈으로 있을때, 1을 더해주기 위한 값인것

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
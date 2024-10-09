//문제 주소 : https://www.acmicpc.net/problem/1929

#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector<bool> IsPrime(1000001, true);
	IsPrime[0] = IsPrime[1] = false;

	int S, E;
	std::cin >> S >> E;

	for (long long i = 2; i <= 1000000; i++)
	{
		if (IsPrime[i] == true)
		{
			for (long long j = i * i; j <= 1000000; j += i)
			{
				IsPrime[j] = false;
			}
		}
	}

	for (int i = S; i <= E; i++)
	{
		if (IsPrime[i]) 
		{
			std::cout << i << '\n';
		}
	}

	return 0;
}
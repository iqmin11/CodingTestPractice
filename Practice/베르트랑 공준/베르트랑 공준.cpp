//문제 주소 : https://www.acmicpc.net/problem/4948

#include <iostream>
#include <vector>

//bool IsPrime(int Value)
//{
//	if (Value == 1)
//	{
//		return false;
//	}
//
//	for (int i = 2; i * i <= Value; i++)
//	{
//		if (Value % i == 0)
//		{
//			return false;
//		}
//	}
//
//	return true;
//}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int Max = 123456 * 2;
	std::vector<bool> IsPrime(Max + 1, true);

	IsPrime[0] = false;
	IsPrime[1] = false;

	for (int i = 2; i * i <= Max; i++)
	{
		for (int j = i + i; j <= Max; j += i)
		{
			IsPrime[j] = false;
		}
	}

	while (true)
	{
		int N;
		std::cin >> N;
		if (N == 0)
		{
			break;
		}

		int Answer = 0;

		for (int i = N + 1; i <= 2 * N; i++)
		{
			if (IsPrime[i])
			{
				Answer++;
			}
		}

		std::cout << Answer << '\n';
	}

	return 0;
}
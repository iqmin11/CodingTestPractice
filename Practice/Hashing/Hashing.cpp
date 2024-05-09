//문제 주소 : https://www.acmicpc.net/problem/15829

#include <iostream>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	unsigned long long N;
	std::string Str;

	std::cin >> N >> Str;

	const unsigned long long r = 31;
	const unsigned long long M = 1234567891;

	unsigned long long Hash = 0;
	for (int i = 0; i < N; i++)
	{
		unsigned long long Pow = 1;
		for (int j = 0; j < i; j++)
		{
			Pow = (Pow % M) * (r % M) % M;
		}
		Hash += (((static_cast<unsigned long long>(Str[i] - 'a') + 1)) * Pow) % M;
	}

	Hash %= M;

	std::cout << Hash;
	return 0;
}
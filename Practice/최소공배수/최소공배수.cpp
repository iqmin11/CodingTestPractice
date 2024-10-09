//문제 주소 : https://www.acmicpc.net/problem/1934

#include <iostream>

//최대공약수
long long GCD(long long Left, long long Right)
{
	long long Mod = Left % Right;
	if (Mod == 0)
	{
		return Right;
	}

	return GCD(Right, Mod);
}

//최소공배수
long long LCM(long long Left, long long Right)
{
	return (Left * Right) / GCD(Left, Right);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long Left, Right;
		std::cin >> Left >> Right;
		std::cout << LCM(Left, Right) << '\n';
	}

	return 0;
}
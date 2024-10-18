//문제 주소 : https://www.acmicpc.net/problem/1629

#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

//사용한 값을 DP에 저장 //DP[n] = Value ^ n
std::unordered_map<long long, long long> DP;

long long Recursive(long long Value, long long Pow, long long Mod)
{
	if (Pow == 1)
	{
		DP[1] = Value % Mod;
		return DP[1];
	}

	long long Half = Pow / 2;
	long long OtherHalf = Pow - Half;
	
	long long Result0 = DP.find(Half) == DP.end() ? Recursive(Value, Half, Mod) % Mod : DP[Half];
	long long Result1 = DP.find(OtherHalf) == DP.end() ? Recursive(Value, OtherHalf, Mod) % Mod : DP[OtherHalf];
	
	DP[Pow] = Result0 * Result1 % Mod;
	return DP[Pow];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long a, b, c;
	std::cin >> a >> b >> c;
	std::cout << Recursive(a, b, c);

	return 0;
}
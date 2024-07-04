//문제 주소 : https://www.acmicpc.net/problem/1351

#include <iostream>
#include <unordered_map>

long long N, P, Q;

std::unordered_map<long long, long long> DP;

long long Recursive(long long Value)
{
	if (DP.find(Value) != DP.end())
	{
		return DP[Value];
	}

	DP[Value] = Recursive(Value / P) + Recursive(Value / Q);
	return DP[Value];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> P >> Q;
	DP[0] = 1;

	std::cout << Recursive(N);

	return 0;
}
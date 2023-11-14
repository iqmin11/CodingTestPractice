#include <iostream>
#include <cmath>

int M = 0;

int Find5Count(int _nFac)
{
	int result = 0;
	int FiveSqua = 0;

	for (int n = 1; FiveSqua <= _nFac; n++)
	{
		FiveSqua = static_cast<int>(pow(5, n));
		result += _nFac / FiveSqua;
	}
	return result;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> M;
	int N = INT32_MAX;

	int lt = 1;
	int rt = 400000015;

	bool Check = false;

	while (lt <= rt)
	{
		int mid = (lt + rt) / 2;
		int Find5 = Find5Count(mid);
		if (Find5 == M)
		{
			N = (mid / 5) * 5;
			std::cout << N;
			Check = true;
			break;
		}
		else if (Find5 > M)
		{
			rt = mid - 1;
		}
		else if (Find5 < M)
		{
			lt = mid + 1;
		}
	}

	if (!Check)
	{
		std::cout << -1;
	}

	return 0;
}
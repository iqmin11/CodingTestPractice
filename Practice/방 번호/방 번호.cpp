//문제 주소 : https://www.acmicpc.net/problem/1082

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool CompGreater(const std::string& Left, const std::string& Right)
{
	size_t LeftSize = Left.size();
	size_t RightSize = Right.size();

	if (LeftSize != RightSize)
	{
		return LeftSize > RightSize;
	}

	return Left > Right;
}

const std::string& MyMax(const std::string& Left, const std::string& Right)
{
	return CompGreater(Left, Right) ? Left : Right;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, Money;

	std::cin >> N;

	std::vector<int> NumPrice;
	NumPrice.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> NumPrice[i];
	}

	std::cin >> Money;

	std::vector<std::string> DP; //DP[m] = m원으로 만들 수 있는 가장 큰 숫자
	DP.resize(Money + 1);

	for (int m = 1; m <= Money; m++)
	{
		for (int i = 0; i < N; i++)
		{
			if (DP[m - 1] == "" && i == 0)
			{
				continue;
			}

			if (NumPrice[i] > m)
			{
				DP[m] = MyMax(DP[m], DP[m - 1]);
			}
			else
			{
				std::string DontAdd = MyMax(DP[m], DP[m - 1]);
				std::string Add = DP[m - NumPrice[i]] + std::to_string(i);

				std::sort(Add.begin(), Add.end(), std::greater<char>());

				DP[m] = MyMax(DP[m], MyMax(Add, DontAdd));
			}
		}
	}
	
	if (!DP.back().empty())
	{
		std::cout << DP.back();
	}
	else
	{
		std::cout << 0;
	}

	return 0;
}
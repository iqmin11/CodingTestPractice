#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
std::vector<int> JemCount;
int envy = INT32_MAX;

bool Check(int _mid)
{
	int People = 0;
	for (size_t i = 0; i < JemCount.size(); i++)
	{
		int tempQuo = JemCount[i] / _mid;
		int tempMod = JemCount[i] % _mid;
		People += tempQuo;
		if (tempMod != 0)
		{
			People++;
		}
	}

	return People <= N && _mid < envy;
}

int main()
{
	std::cin >> N >> M;
	
	JemCount.reserve(M);

	int lt = 1;
	int rt = INT32_MIN;

	for (size_t i = 0; i < M; i++)
	{
		int tempCount;
		std::cin >> tempCount;
		JemCount.push_back(tempCount);

		if (rt < tempCount)
		{
			rt = tempCount;
		}
	}

	while (lt <= rt)
	{
		int mid = (lt + rt) / 2;
		if (Check(mid))
		{
			envy = mid;
			rt = mid - 1;
		}
		else
		{
			lt = mid + 1;
		}
	}
	
	std::cout << envy;
	
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

//최대값 : 제일적은 보석의 개수
//최소값 : 1
//mod가 가장 큰거 + 나누기값 = 질투심

int N, M;

int main()
{
	std::cin >> N >> M;

	int lt = 1;
	int rt = INT32_MIN;
	std::vector<int> JemTypes;
	JemTypes.reserve(M);

	for (size_t i = 0; i < M; i++)
	{
		int temp;
		std::cin >> temp;
		if (rt < temp)
		{
			rt = temp;
		}
		JemTypes.emplace_back(temp);
	}

	int Envy = INT32_MAX;

	while (lt <= rt)
	{
		int mid = (rt + lt) / 2;
		int People = 0;

		int MAXMod = INT32_MIN;
		for (size_t i = 0; i < JemTypes.size(); i++)
		{
			int Quo = JemTypes[i] / mid;
			People += Quo;
			int Mod = JemTypes[i] % mid;

			if (Mod != 0)
			{
				//여기가 어케해야대지
			}

			if (Mod > MAXMod)
			{
				MAXMod = Mod;
			}
		}

		if (People <= N)
		{
			int tempEnvy = MAXMod + mid;
			if (tempEnvy < Envy)
			{
				Envy = tempEnvy;
				rt = mid - 1;
			}
			else
			{
				lt = mid + 1;
			}
		}
		else
		{
			lt = mid + 1;
		}

	}

	std::cout << Envy;

	return 0;
}
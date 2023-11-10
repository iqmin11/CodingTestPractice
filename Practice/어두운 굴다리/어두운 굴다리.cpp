#include <iostream>
#include <vector>

int N, M;
std::vector<int> Pos;

bool IsAllLightOn(int _mid)
{
	int prevMAX = 0;
	bool IsAllLightOnCheck = true;
	for (int i = 0; i < Pos.size(); i++)
	{
		if (_mid == 0)
		{
			return false;
		}

		int minIndex = Pos[i] - _mid;
		if (minIndex < 0)
		{
			minIndex = 0;
		}
		int MAXIndex = Pos[i] + _mid - 1;
		if (MAXIndex >= N)
		{
			MAXIndex = static_cast<int>(N - 1);
		}

		if (Pos.size() - 1 == 0)
		{
			if (0 != minIndex || N - 1 != MAXIndex)
			{
				return IsAllLightOnCheck &= false;
			}
		}
		else
		{
			if (i == 0)
			{
				if (0 != minIndex)
				{
					return IsAllLightOnCheck &= false;
				}
			}
			else if (i == Pos.size() - 1)
			{
				if (N - 1 != MAXIndex)
				{
					return IsAllLightOnCheck &= false;
				}
			}
			else if (prevMAX + 1 < minIndex)
			{
				return IsAllLightOnCheck &= false;
			}
		}

		prevMAX = MAXIndex;
	}
	return IsAllLightOnCheck;
}

int main()
{
	std::cin >> N >> M;
	Pos.reserve(M);
	for (int i = 0; i < Pos.capacity(); i++)
	{
		int temp;
		std::cin >> temp;
		Pos.emplace_back(temp);
	}
	int lt = 0;
	int rt = static_cast<int>(N);
	int mid = ((rt - lt) / 2) + lt;
	int LightSize = 0;

	while (lt <= rt)
	{
		mid = ((rt - lt) / 2) + lt;

		if (IsAllLightOn(mid))
		{
			rt = mid - 1;
			LightSize = mid;
		}
		else
		{
			lt = mid + 1;
		}
	}

	std::cout << LightSize;

	return 0;
}
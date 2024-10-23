//문제 주소 : https://www.acmicpc.net/problem/2997

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector<int> Arr(3, 0);

	for (int i = 0; i < 3; i++)
	{
		std::cin >> Arr[i];
	}

	std::sort(Arr.begin(), Arr.end());

	int Differ = (Arr[1] - Arr[0]) > (Arr[2] - Arr[1]) ? (Arr[2] - Arr[1]) : (Arr[1] - Arr[0]);

	for (int i = 1; i < 3; i++)
	{
		if (Arr[i] - Arr[i - 1] != Differ)
		{
			std::cout << Arr[i - 1] + Differ;
			return 0;
		}
	}
	
	std::cout << Arr[2] + Differ;
	return 0;
}
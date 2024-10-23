//문제 주소 : https://www.acmicpc.net/problem/28292

#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	if (N < 3)
	{
		std::cout << 1;
	}
	else if (N < 6)
	{
		std::cout << 2;
	}
	else
	{
		std::cout << 3;
	}

	/*std::vector<std::string> Arr(100);
	Arr[0] = "1"; 

	for (int i = 1; i < 100; i++)
	{
		char Prev = '\0';
		std::vector<std::string> Cur;
		for (int j = 0; j < Arr[i - 1].size(); j++)
		{
			if (Prev != Arr[i - 1][j])
			{
				Cur.push_back(std::string());
				Prev = Arr[i - 1][j];
			}

			Cur.back().push_back(Arr[i - 1][j]);
		}

		for (int k = 0; k < Cur.size(); k++)
		{
			Arr[i].push_back(Cur[k][0]);
			Arr[i] += std::to_string(Cur[k].size());
		}
	}*/
	return 0;
}
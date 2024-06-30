//���� �ּ� : https://www.acmicpc.net/problem/2877

#include <iostream>
#include <deque>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//4 1��° 
	//7
	//44 3��°
	//47
	//74
	//77
	//444 7��°
	//447
	//474
	//477
	//744
	//747
	//774
	//777
	//4444 15��°
	//44444 31��°
	//444444 63��°


	int N;
	std::cin >> N;

	int CopyN = N + 1;
	int Count = 0;
	int Pow = 1;
	while (CopyN != 1)
	{
		CopyN /= 2;
		Pow *= 2;
		Count++;
	}

	std::deque<char> Answer;
	int Mod = N - (Pow - 1);

	for (int i = 0; i < Count; i++)
	{
		if (Mod >> i & 1)
		{
			Answer.push_front('7');
		}
		else
		{
			Answer.push_front('4');
		}
	}

	for (const auto i : Answer)
	{
		std::cout << i;
	}

	return 0;
}
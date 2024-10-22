//���� �ּ� : https://www.acmicpc.net/problem/3078

#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;
	std::cin >> N >> K;

	std::vector<int> Arr;
	Arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		std::string temp;
		std::cin >> temp;
		Arr[i] = static_cast<int>(temp.size());
	}

	int Right = 0;
	std::vector<long long> NameCount(21, 0); //NameCount[a] = �̸����� a¥�� ģ���� ������ȿ� �

	long long Answer = 0; //Window�� �Ǿ� ���Ҹ� �������� ����ģ������ ���� �����ش�

	for (int Left = 0; Left < N; Left++)
	{
		while (Right - Left <= K && Right < N)
		{
			NameCount[Arr[Right]]++;
			Right++;
		}

		Answer += NameCount[Arr[Left]] - 1;
		NameCount[Arr[Left]]--;
	}

	std::cout << Answer;

	return 0;
}
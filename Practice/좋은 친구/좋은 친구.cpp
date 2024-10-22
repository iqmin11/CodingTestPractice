//문제 주소 : https://www.acmicpc.net/problem/3078

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
	std::vector<long long> NameCount(21, 0); //NameCount[a] = 이름길이 a짜리 친구가 윈도우안에 몇개

	long long Answer = 0; //Window의 맨앞 원소를 기준으로 좋은친구쌍을 세서 더해준다

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
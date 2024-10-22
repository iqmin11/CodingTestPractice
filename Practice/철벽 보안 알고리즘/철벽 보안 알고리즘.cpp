//문제 주소 : https://www.acmicpc.net/problem/9322

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		std::cin >> N;
		
		// TODO: 공개키1 구현 
		std::unordered_map<std::string, int> PublicKey1Order; //어떤 단어가 어떤 인덱스에 있는가
		{
			for (int i = 0; i < N; i++)
			{
				std::string PublicKey1;
				std::cin >> PublicKey1;
				PublicKey1Order.insert(std::make_pair(PublicKey1, i));
			}
		}

		// TODO: 공개키2 구현
		std::vector<std::pair<int, std::string>> PublicKey2Order; //어떤 1인덱스에 어떤 단어가 있는가
		{
			PublicKey2Order.reserve(N);
			for (int i = 0; i < N; i++)
			{
				std::string PublicKey2;
				std::cin >> PublicKey2;

				int OriginIndex = PublicKey1Order[PublicKey2];

				PublicKey2Order.push_back(std::make_pair(OriginIndex, std::string()));
			}
		}

		// TODO: 암호문 입력
		for (int i = 0; i < N; i++)
		{
			std::cin >> PublicKey2Order[i].second;
		}

		// TODO: 정렬
		std::sort(PublicKey2Order.begin(), PublicKey2Order.end());

		// TODO: 출력
		for (int i = 0; i < N; i++)
		{
			std::cout << PublicKey2Order[i].second << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}
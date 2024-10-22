//���� �ּ� : https://www.acmicpc.net/problem/9322

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
		
		// TODO: ����Ű1 ���� 
		std::unordered_map<std::string, int> PublicKey1Order; //� �ܾ � �ε����� �ִ°�
		{
			for (int i = 0; i < N; i++)
			{
				std::string PublicKey1;
				std::cin >> PublicKey1;
				PublicKey1Order.insert(std::make_pair(PublicKey1, i));
			}
		}

		// TODO: ����Ű2 ����
		std::vector<std::pair<int, std::string>> PublicKey2Order; //� 1�ε����� � �ܾ �ִ°�
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

		// TODO: ��ȣ�� �Է�
		for (int i = 0; i < N; i++)
		{
			std::cin >> PublicKey2Order[i].second;
		}

		// TODO: ����
		std::sort(PublicKey2Order.begin(), PublicKey2Order.end());

		// TODO: ���
		for (int i = 0; i < N; i++)
		{
			std::cout << PublicKey2Order[i].second << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}
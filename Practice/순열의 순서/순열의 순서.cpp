//https://www.acmicpc.net/problem/1722

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

long long Factorial[21];

int main()
{
	Factorial[0] = 1;
	Factorial[1] = 1;
	for (int i = 2; i <= 20; i++)
	{
		Factorial[i] = Factorial[i - 1] * i;
	}

	int N;
	std::cin >> N;
	std::set<int> Nums;
	for (int i = 1; i <= N; i++)
	{
		Nums.insert(i);
	}

	long long Case;
	std::cin >> Case;

	if (Case == 1)
	{
		//0 -> 1234
		//Nums���� Rank 0
		//Nums���� Rank 0
		//Nums���� Rank 0
		//Nums���� Rank 0

		//1 -> 1243
		//Nums���� Rank 0
		//Nums���� Rank 0
		//Nums���� Rank 1
		//Nums���� Rank 0

		//23 -> 4321
		//Nums���� Rank 3
		//Nums���� Rank 2
		//Nums���� Rank 1
		//Nums���� Rank 0

		//�˰� �ִ°� �ڸ�����, Order
		long long Order; //23
		std::cin >> Order;
		--Order;

		//�˰������ ����
		std::vector<int> Arr(N);
		
		//����
		//1 2 6 24 120

		for (int i = 0; i < N; i++)
		{
			long long Rank = Order / Factorial[N - 1 - i];
			Order %= Factorial[N - 1 - i];

			auto FindIter = Nums.begin();
			std::advance(FindIter, Rank);
			Arr[i] = *FindIter;
			Nums.erase(FindIter);
		}

		for (int i = 0; i < N; i++)
		{
			std::cout << Arr[i] << ' ';
		}

	}
	else if (Case == 2)
	{
		//���� �Է¹ޱ�
		std::vector<int> Arr(N);
		for (int i = 0; i < N; i++)
		{
			std::cin >> Arr[i];
		}

		long long Order = 0;
		for (int i = 0; i < N - 1; i++)
		{
			//���� Ž���ϴ� ���ڰ� ���� ������ ���° �������� Ȯ��
			//0��°(���� �켱������ ����)

			auto FindIter = Nums.find(Arr[i]);
			long long Rank = std::distance(Nums.begin(), FindIter);
			Nums.erase(FindIter);

			//1243
			//1 0
			//2 0
			//4 1

			//1

			//4321
			//4 3 -> 3 * 3! -> 18
			//3 2 -> 2 * 2! -> 4
			//2 1 -> 1 * 1! -> 1
			//0 ~ 23

			// Rank * (Digit - 1)!

			Order += Rank * Factorial[(N - 1) - i];
		}

		std::cout << Order + 1;
	}

	return 0;
}

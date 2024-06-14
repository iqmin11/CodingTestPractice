//문제 주소 : https://www.acmicpc.net/problem/2661

#include <iostream>
#include <deque>

//1. 백트래킹으로 숫자 하나씩 추가하기.
//2. 슬라이딩윈도우로 검사하기.

int N;
std::deque<int> Nums;

bool IsPossible(int i)
{
	Nums.push_back(i);
	int NumsSize = Nums.size();
	int WindowSize = 2;

	while (WindowSize <= NumsSize)
	{
		std::deque<int> Window;
		int right = 0;

		for (int left = 0; left < NumsSize - WindowSize + 1; left++)
		{
			while (Window.size() < WindowSize && right < NumsSize)
			{
				Window.push_back(Nums[right]);
				right++;
			}

			//윈도우를 반절 잘라서 앞뒤가 같은지 확인함
			int CheckSize = WindowSize / 2;
			bool IsSame = true;
			for (int i = 0; i < CheckSize; i++)
			{
				if (Window[i] != Window[i + CheckSize])
				{
					IsSame = false;
					break;
				}
			}

			if (IsSame)
			{
				Nums.pop_back();
				return false;
			}

			Window.pop_front();
		}

		WindowSize += 2; //짝수 크기 윈도우만 확인하면 됨
	}

	Nums.pop_back();
	return true;
}

void BT()
{
	if (Nums.size() == N)
	{
		//답 출력
		for (int i = 0; i < Nums.size(); i++)
		{
			std::cout << Nums[i];
		}

		std::exit(0);
	}

	for (size_t i = 1; i <= 3; i++)
	{
		if (!IsPossible(i))
		{
			continue;
		}

		Nums.push_back(i);
		BT();
		Nums.pop_back();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	BT();

	return 0;
}
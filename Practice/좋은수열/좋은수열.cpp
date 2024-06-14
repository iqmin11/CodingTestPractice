//���� �ּ� : https://www.acmicpc.net/problem/2661

#include <iostream>
#include <deque>

//1. ��Ʈ��ŷ���� ���� �ϳ��� �߰��ϱ�.
//2. �����̵�������� �˻��ϱ�.

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

			//�����츦 ���� �߶� �յڰ� ������ Ȯ����
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

		WindowSize += 2; //¦�� ũ�� �����츸 Ȯ���ϸ� ��
	}

	Nums.pop_back();
	return true;
}

void BT()
{
	if (Nums.size() == N)
	{
		//�� ���
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
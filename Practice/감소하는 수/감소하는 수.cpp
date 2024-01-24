#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> NumSelect(int _r)
{
	std::vector<int> Select;
	Select.resize(10, 1);
	for (size_t i = 0; i < _r; i++)
	{
		Select[i] = 0;
	}
	return Select;
}

int main()
{
	//���� �� ����Ʈ
	std::string NumList = { '0','1','2','3','4','5','6','7','8','9' };
	std::vector<long long> ReduceNumList;
	ReduceNumList.reserve(1024);

	//next permutation���� 10�� �� r���� �� �̱�
	for (size_t r = 1; r <= 10; r++)
	{
		std::vector<int> Combination = NumSelect(r);
		do
		{
			std::string CurNum;
			for (size_t i = 0; i < Combination.size(); i++)
			{
				if (Combination[i] == 0)
				{
					CurNum += NumList[i]; //�ε����� Ȱ���Ͽ� ���� ����
				}
			}

			std::sort(CurNum.begin(), CurNum.end(), [](char _left, char _right) //�������� ����
				{
					return _left > _right;
				});
			
			long long Temp = 0;
			int Count = 0;
			Temp = std::stoll(CurNum);

			ReduceNumList.push_back(Temp);
		} while (std::next_permutation(Combination.begin(), Combination.end()));
	}
	std::sort(ReduceNumList.begin(), ReduceNumList.end());

	int N;
	std::cin >> N;

	if (N < ReduceNumList.size())
	{
		std::cout << ReduceNumList[N];
	}
	else
	{
		std::cout << -1;
	}

}
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

//�������� ���� ���� []���۷����͸� �� �Ẹ���� ����

int main()
{
	int N, C;
	std::cin >> N;
	std::cin >> C;

	std::map<int, int> C_frequency = std::map<int, int>(); //C�� �󵵸� ���� (� ���ڰ�, ���)
	std::map<int, int> C_Order = std::map<int, int>(); //C�� ������ ����
	int Order = 0; //���� �Է¿�

	for (size_t i = 0; i < N; i++)
	{
		int CurKey = 0;
		std::cin >> CurKey;
		std::pair<std::map<int, int>::iterator, bool> InsertResult = C_frequency.insert(std::make_pair(CurKey, 1));
		if (!InsertResult.second) // bool�� insert ���� �����̴� ����->true
		{
			InsertResult.first->second++;
		}
		else
		{
			C_Order.insert(std::make_pair(CurKey, ++Order)); // ���� ������ ������ ����
		}
	}
	
	std::vector<std::pair<int, int>> C_frequency_Vec(C_frequency.begin(), C_frequency.end()); //���� �� ���Ŀ��ε�
	//�̷��� �ʱ�ȭ�� �����ϴٰ�????? ��¾��

	//for (auto& i : C_frequency)
	//{
	//	C_frequency_Vec.emplace_back(std::make_pair(i.first, i.second)); //���� ���ͷ� ����
	//}

	std::sort(C_frequency_Vec.begin(), C_frequency_Vec.end(), [=](std::pair<int, int> _left, std::pair<int, int> _right)
		{
			if (_left.second == _right.second) //�󵵰� ������
			{
				return C_Order.find(_left.first)->second < C_Order.find(_right.first)->second; //���� ��������
			}
			return _left.second > _right.second; //�� �������� ����
		});

	for (size_t i = 0; i < C_frequency_Vec.size(); i++)
	{
		for (size_t j = 0; j < C_frequency_Vec[i].second; j++) //�󵵸�ŭ ���鼭
		{
			std::cout << C_frequency_Vec[i].first << " "; //���
		}
	}

	return 0;
}
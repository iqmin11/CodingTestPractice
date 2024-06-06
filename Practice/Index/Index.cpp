#include <iostream>
#include <vector>
#include <map>

int main()
{
	//���� ������ ���̺�
	std::vector<std::vector<int>> DataTable =
	{
		{3, 4, 5, 6, 0, 1, 2},
		{1, 2, 3, 4, 5, 6, 0},
		{2, 3, 4, 5, 6, 0, 1},
		{6, 0, 1, 2, 3, 4, 5},
		{4, 5, 6, 0, 1, 2, 3},
		{0, 1, 2, 3, 4, 5, 6},
		{5, 6, 0, 1, 2, 3, 4},
	};

	//����° ��(DataTable[2])�� indexȭ �ϰ� �;� => �����͵��� �������� ���ڴٴ� �� -> ���?
	
	//�̷���
	std::map<int, std::vector<int>*> C_2Index;
	
	for (int i = 0; i < 7; i++)
	{
		C_2Index.insert(std::make_pair(DataTable[i][2], &DataTable[i]));
	}
	// => ������ ������ � �ڷᱸ���� ����ص� ��� ������, �Ϲ������� B-tree �迭�� �ڷᱸ���� ���
	// ������ ������ �ڷᱸ���� ����ϴ� ����.
	// 1) ���� Ž��(�Ǵ� M�� Ž��??)�� ����� �� �ִ�(�˻��ӵ� O(logN))
	// 2) ���� ��� �����͸� ã�� �� �ִ�
	 
	//Hash Table�� ���, �ڷᰡ ���������� ���ĵ��� ����. �׷��� ������ ���� ��� �����͸� Find�� �� ����.
	//�׷��� �˻� �ӵ��� O(1)�̱� ������ ���� ��� �����͸� ã�� �ʿ� ���� Index�� Hash Table�� indexȭ �ϸ� ������.

	//�ڷ� Read
	//ex ) C_2�� 0�� Tuple�� ù��°(C_0) ���� �ڷḦ ���� ����;�

	auto FindIter = C_2Index.find(0);
	if (FindIter == C_2Index.end())
	{
		return; // �˻� ����
	}

	std::vector<int>* FindTuple = FindIter->second;
	int& FindValue = (*FindTuple)[0];

	//�ڷ� write
	//ex) ã�ƿ� �ڷ� 5�� 7�� �ٲٰ�;�
	FindValue = 7;
}
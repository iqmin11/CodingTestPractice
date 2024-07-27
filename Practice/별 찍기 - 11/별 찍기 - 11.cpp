//���� �ּ� : https://www.acmicpc.net/problem/2448

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> Target;

void DrawRecursive(int R, std::pair<int, int> Pivot) //�ﰢ���� ũ��, �Ǻ�(x,y)
{
	if (R == 3)
	{
		//�׸� �׸���
		Target[Pivot.second][Pivot.first] = '*';
		Target[Pivot.second + 1][Pivot.first - 1] = '*';
		Target[Pivot.second + 1][Pivot.first + 1] = '*';
		Target[Pivot.second + 2][Pivot.first - 2] = '*';
		Target[Pivot.second + 2][Pivot.first - 1] = '*';
		Target[Pivot.second + 2][Pivot.first] = '*';
		Target[Pivot.second + 2][Pivot.first + 1] = '*';
		Target[Pivot.second + 2][Pivot.first + 2] = '*';

		return;
	}

	int NextTriHight = R / 2;
	DrawRecursive(NextTriHight, Pivot);//��� �� �ﰢ��
	DrawRecursive(NextTriHight, std::make_pair(Pivot.first - NextTriHight, Pivot.second + NextTriHight));//���� �Ʒ� �ﰢ��
	DrawRecursive(NextTriHight, std::make_pair(Pivot.first + NextTriHight, Pivot.second + NextTriHight));//������ �Ʒ� �ﰢ��
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	//���� N ���� 2N - 1
	int R, C;
	std::cin >> R;
	C = 2 * R - 1;
	
	Target.resize(R);
	for (int i = 0; i < R; i++)
	{
		Target[i].resize(C, ' ');
	}

	//�ϳ��� ��ͽ���Ŭ�� �ﰢ�� ������ �׸��� ������ �̷���� ����.
	DrawRecursive(R, std::make_pair(R - 1, 0));

	for (int i = 0; i < R; i++)
	{
		std::cout << Target[i] << '\n';
	}

	return 0;
}
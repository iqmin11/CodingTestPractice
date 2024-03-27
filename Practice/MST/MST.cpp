#include <iostream>
#include <vector>
#include <queue>

int Data[10][10] =
{
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	{ 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 },
	{ 2, 2, 0, 3, 4, 5, 6, 7, 8, 9 },
	{ 3, 3, 3, 0, 4, 5, 6, 7, 8, 9 },
	{ 4, 4, 4, 4, 0, 5, 6, 7, 8, 9 },
	{ 5, 5, 5, 5, 5, 0, 6, 7, 8, 9 },
	{ 6, 6, 6, 6, 6, 6, 0, 7, 8, 9 },
	{ 7, 7, 7, 7, 7, 7, 7, 0, 8, 9 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 0, 9 },
	{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 0 },
};

std::priority_queue<std::pair<long long, std::pair<int, int>>> EdgeInfo; //Cost, ���� ��� ���� (�ּ� �ڽ�Ʈ �������� �׸����ϰ� ���� ������ pq�� ���)
std::vector<int> Parent; //��ǻ� �ڱⰡ ���� ������ �̸�
//(Parent[a] = b) -> a�� ���� ������ b�̴�...�ε� ��Ȯ�ϰ� �װ� ���ϴ°��� �ƴϰ�, ��¥ �Ҽ��� ã�� ���ؼ��� Find�Լ��� ��������

int FindParent(int Value) //��ͽ����� Ž���Ͽ� ���� �Ѹ� ������ ã����
{
	if (Parent[Value] == Value) //�ε����� ���� ������ �ʱ⿡ ������ �Ѹ�����
	{
		return Value;
	}
	Parent[Value] = FindParent(Parent[Value]); //�ٸ��ٸ� �Ѹ������� ã�������� ���
	return Parent[Value];
}

void Union(int FirstParent, int SecondParent) //���� FindParent�� �ι��ϴ°��� ������ ���� �ʾƼ� �ƿ� ���ڷ� Parent�� �ް� �Ͽ����ϴ�.
{
	//�׳� Union�ϰ��� �ϴ� ���Ҹ� ���ڷ� �ް�, �ȿ��� Parent�� ã���� �� �����ϴ°͵� ����������, ������ �����ܰ迡�� Parent�� ã�� ���ƾ���
	if (FirstParent < SecondParent) //�ϰ��� ��Ģ���� ������ ������ �ؾ��ϳ�???
	{
		Parent[SecondParent] = FirstParent;
	}
	else
	{
		Parent[FirstParent] = SecondParent;
	}
}

void MST_Kruskal(int N) //������ ����
{
	int EdgeCount = 0;
	while (!EdgeInfo.empty() && EdgeCount < N - 1)
	{
		int CheckCost = -EdgeInfo.top().first;
		int FirstNode = EdgeInfo.top().second.first;
		int SecondNode = EdgeInfo.top().second.second;
		EdgeInfo.pop();

		int FirstParent = FindParent(FirstNode);
		int SecondParent = FindParent(SecondNode);
		if (FirstParent != SecondParent) //�̰������� ������ Find�� �������. �� ���Ұ� ���μ� �������� �ƴ��� �ľ��ϴ� �κ�, ���μҶ�� ��ȸ�����ʱ⶧����
		{
			Union(FirstParent, SecondParent); //�� ������ ��ġ��
			
			//������ �����ϰԵ�
			//���⼭ �������� �ϰ��ִ� ������ �����ϸ� �˴ϴ�. ������ �����ٴ���, �ּ��ڽ�Ʈ�� ����Ѵٴ���..
			++EdgeCount;
		}
	}
}

int main()
{
	Parent.resize(10); //����� ������ŭ ����

	for (int i = 0; i < 10; i++)
	{
		Parent[i] = i; //�Ѹ����� ����
		for (int j = 0; j < i; j++)
		{
			EdgeInfo.push(std::make_pair(-Data[i][j], std::make_pair(i, j))); //�������� ������ ���� �ڽ�Ʈ�� -Data�� �Է�
		}
	}

	MST_Kruskal(10);
}
#include <iostream>
#include <vector>

int main()
{
	int H, W;
	std::cin >> H >> W;

	std::vector<int> WallHight;
	WallHight.resize(W);
	for (int i = 0; i < WallHight.size(); i++)
	{
		std::cin >> WallHight[i];
	}

	//1. �����̶�? 
	//ó�� üũ�ϴ� �� ����
	//���������� ���鼭 ù��° �� ���� �̻��� ���� ������ ����
	//���������� ���鼭 �� ���̸� ����
	//���� ���� ���� ������ �� Ȯ���ϰ� ������ �������� ������

	int left = 0;
	int right = 1;
	int Answer = 0;
	int CurCount = 0;
	
	while (right < W)
	{
		if (WallHight[right-1] <= WallHight[right] && WallHight[right + 1] < WallHight[right])
		{
			if (WallHight[left] > WallHight[right])
			{
				CurCount = CurCount - (WallHight[left] - WallHight[right])*(right - left - 1);
			}

			Answer += CurCount;

			left = right + 1;
			right = left + 1;
		}
		else
		{
			CurCount += WallHight[left] - WallHight[right];
			right++;
		}
	}


	return 0;
}
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

	//1. 웅덩이란? 
	//처음 체크하는 벽 기준
	//오른쪽으로 가면서 첫번째 벽 높이 이상인 벽을 만나면 종료
	//오른쪽으로 가면서 벽 높이를 저장
	//가장 왼쪽 가장 오른쪽 벽 확인하고 낮은애 기준으로 샤샤샷

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
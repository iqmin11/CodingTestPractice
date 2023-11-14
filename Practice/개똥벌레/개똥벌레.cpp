#include <iostream>
#include <vector>
#include <algorithm>

int N, H; //���̿� ����(����)
std::vector<int> UpObs; //����
std::vector<long long> DownObs; //������

void Init()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
}

int main()
{
	Init();

	std::cin >> N >> H;
	UpObs.reserve(N);
	DownObs.reserve(N);

	//��ֹ� �׸���
	for (size_t i = 0; i < N; i++)
	{
		int ObstacleSize;
		std::cin >> ObstacleSize;

		if (i % 2 == 0) //¦�� �ε����� ���
		{
			UpObs.emplace_back(ObstacleSize);
		}
		else // Ȧ�� �ε����� ���
		{
			DownObs.emplace_back(ObstacleSize);
		}
	}

	std::sort(UpObs.begin(), UpObs.end());
	std::sort(DownObs.begin(), DownObs.end());
	int MinCount = INT32_MAX;
	int SameObsPath = 1;

	for (int i = 0; i < H; i++)
	{
		long long ObstacleCount = 0;

		//���� �ε���(���̱���)�� i�϶� i + 1(��¥ ����)�̻��ΰ� �?
		ObstacleCount += UpObs.end() - std::lower_bound(UpObs.begin(), UpObs.end(), i + 1);
		//i�϶� �������� H  - i 
		ObstacleCount += DownObs.end() - std::lower_bound(DownObs.begin(), DownObs.end(), H - i);

		if (MinCount > ObstacleCount)
		{
			MinCount = ObstacleCount;
			SameObsPath = 1;
			continue;
		}
		else if (MinCount == ObstacleCount)
		{
			SameObsPath++;
		}
	}

	std::cout << MinCount << " " << SameObsPath;

	return 0;
}
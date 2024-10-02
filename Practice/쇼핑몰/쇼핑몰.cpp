//문제 주소 : https://www.acmicpc.net/problem/17612

#include <iostream>
#include <queue>
#include <algorithm>

struct CmpEndTime
{
	bool operator()(const std::vector<int>& Left, const std::vector<int>& Right)
	{
		if (Left.size() != 3 || Right.size() != 3)
		{
			std::cout << "CmpError" << '\n';
			return false;
		}

		if (Left[1] == Right[1])
		{
			return Left[2] < Right[2];
		}

		return Left[1] > Right[1];
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;
	std::cin >> N >> K;

	std::queue<std::pair<int, int>> WaitJob;

	for (int i = 0; i < N; i++)
	{
		std::pair<int, int> Temp;
		std::cin >> Temp.first >> Temp.second;
		WaitJob.push(std::move(Temp));
	}

	//끝나는 시간 기준으로 넣자
	//vector는 id, endtime, Autiority
	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, CmpEndTime> RunJob;
	
	//계산대 점유 권한
	std::priority_queue<int, std::vector<int>, std::greater<int>> Authority;
	for (int i = 1; i <= K; i++)
	{
		Authority.push(i);
	}
	
	int CurTime = 0;
	long long Order = 0;
	long long Answer = 0;

	while (!WaitJob.empty() || !RunJob.empty())
	{
		//TODO: K개까지 WaitJob을 넣어야함
		while (!Authority.empty())
		{
			if (WaitJob.empty())
			{
				break;
			}

			//TODO: 걸리는 시간을 EndTime으로 치환후 RunJob에 넣기
			//id, EndTime, Authority
			std::vector<int> CurJob(3);
			CurJob[0] = WaitJob.front().first;
			CurJob[1] = WaitJob.front().second;
			CurJob[2] = Authority.top();
			WaitJob.pop();
			Authority.pop();

			CurJob[1] += CurTime;
			RunJob.push(std::move(CurJob));
		}
		
		CurTime = RunJob.top()[1];

		while (!RunJob.empty())
		{
			if (RunJob.top()[1] > CurTime)
			{
				break;
			}

			Answer += (++Order) * RunJob.top()[0];
			Authority.push(RunJob.top()[2]);
			RunJob.pop();
		}
	}

	std::cout << Answer;

	return 0;
}
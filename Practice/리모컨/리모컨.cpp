//https://www.acmicpc.net/problem/1107

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::vector<bool> Remotecon; //해당 조건에맞는 숫자 찾기

int main()
{
	int N, M; //이 숫자와 가장 가까운

	std::cin >> N >> M;

	Remotecon.resize(10, true);

	for (int i = 0; i < M; i++)
	{
		int temp;
		std::cin >> temp;
		Remotecon[temp] = false;
	}

	//1. 가장 가까운 큰수 찾기
	
	//1-1. 앞 자리 수 부터 체크
	//1-2. 조건에 어긋나는 가장 앞자릿수를 가장 가까운 큰수로 만듦
	//1.3. 그다음 자릿수부터는 0부터 시작해서 조건에 어긋나지 않는 가장 작은수로 채우면 됨
	
	std::string Nstr = std::to_string(N);
	std::string MostNearNumBigger;
	MostNearNumBigger.resize(Nstr.size(), 'N'); // 감시값으로 초기화 N이 남아있으면 해당 조건의 큰수는 만드는 것이 불가능 하다는 뜻

	for (int i = 0; i < Nstr.size(); ++i)
	{
		if (Remotecon[Nstr[i] - '0']) // 가능한 숫자면
		{
			MostNearNumBigger[i] = Nstr[i];
			continue; //컨티뉴
		}
		else
		{
			//불가능한 숫자면
			for (char j = Nstr[i] + 1; j <= '9'; j++) // 가장 가까운 큰수를 찾음
			{
				if (Remotecon[j - '0']) //찾으면
				{
					//넣음
					MostNearNumBigger[i] = j;
					int SmallestNum = 0;
					for (int k = 0; k < 10; k++)
					{
						if (Remotecon[k])
						{
							SmallestNum = k;
							break;
						}
					}
					
					for (i = i + 1; i < Nstr.size(); i++) // 다음자리 숫자부터
					{
						MostNearNumBigger[i] = SmallestNum + '0';
					}

					break; //끝나면 탈출
				}
			}
		}
	}

	//같은 짓을 작은놈으로도 만들기
	std::string MostNearNumSmaller;
	MostNearNumSmaller.resize(Nstr.size(), 'N');

	for (int i = 0; i < Nstr.size(); ++i)
	{
		if (Remotecon[Nstr[i] - '0']) // 가능한 숫자면
		{
			MostNearNumSmaller[i] = Nstr[i];
			continue; //컨티뉴
		}
		else
		{
			//불가능한 숫자면
			for (char j = Nstr[i] - 1; j >= '0'; j--) // 가장 가까운 작은수를 찾음
			{
				if (Remotecon[j - '0'] || (i == 0 && j == '0')) //찾으면
				{
					//넣음
					MostNearNumSmaller[i] = j;
					int BigestNum = 0;
					for (int k = 9; k >= 0; k--)
					{
						if (Remotecon[k])
						{
							BigestNum = k;
							break;
						}
					}

					for (i = i + 1; i < Nstr.size(); i++) // 다음자리 숫자부터
					{
						MostNearNumSmaller[i] = BigestNum + '0';
					}

					break; //끝나면 탈출
				}
			}
		}
	}

	int Differ1 = -1;
	int Differ2 = -1;
	int Num1 = -1;
	int Num2 = -1;

	for (int i = 0; i < MostNearNumBigger.size(); i++)
	{
		if (MostNearNumBigger[i] == 'N')
		{
			Differ1 = INT32_MAX;
			break;
		}
	}

	if (Differ1 != INT32_MAX)
	{
		Num1 = std::stoi(MostNearNumBigger);
		Differ1 = std::abs(Num1 - N);
	}

	for (int i = 0; i < MostNearNumSmaller.size(); i++)
	{
		if (MostNearNumSmaller[i] == 'N')
		{
			Differ2 = INT32_MAX;
			break;
		}
	}

	if (Differ2 != INT32_MAX)
	{
		Num2 = std::stoi(MostNearNumSmaller);
		Differ2 = std::abs(Num2 - N);
	}

	int NearNum = 0;

	if (Differ1 < Differ2)
	{
		NearNum = Num1;
	}
	else
	{
		NearNum = Num2;
	}

	int Count1 = std::abs(N - 100);
	int Count2 = INT32_MAX;
	
	if (NearNum  != -1)
	{
		Count2 = std::to_string(NearNum).size() + std::abs(N - NearNum);
	}


	int Answer = std::min(Count1, Count2);
	std::cout << Answer;

	return 0;
}
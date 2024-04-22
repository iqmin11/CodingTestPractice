//https://www.acmicpc.net/problem/1107

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::vector<bool> Remotecon; //�ش� ���ǿ��´� ���� ã��

int main()
{
	int N, M; //�� ���ڿ� ���� �����

	std::cin >> N >> M;

	Remotecon.resize(10, true);

	for (int i = 0; i < M; i++)
	{
		int temp;
		std::cin >> temp;
		Remotecon[temp] = false;
	}

	//1. ���� ����� ū�� ã��
	
	//1-1. �� �ڸ� �� ���� üũ
	//1-2. ���ǿ� ��߳��� ���� ���ڸ����� ���� ����� ū���� ����
	//1.3. �״��� �ڸ������ʹ� 0���� �����ؼ� ���ǿ� ��߳��� �ʴ� ���� �������� ä��� ��
	
	std::string Nstr = std::to_string(N);
	std::string MostNearNumBigger;
	MostNearNumBigger.resize(Nstr.size(), 'N'); // ���ð����� �ʱ�ȭ N�� ���������� �ش� ������ ū���� ����� ���� �Ұ��� �ϴٴ� ��

	for (int i = 0; i < Nstr.size(); ++i)
	{
		if (Remotecon[Nstr[i] - '0']) // ������ ���ڸ�
		{
			MostNearNumBigger[i] = Nstr[i];
			continue; //��Ƽ��
		}
		else
		{
			//�Ұ����� ���ڸ�
			for (char j = Nstr[i] + 1; j <= '9'; j++) // ���� ����� ū���� ã��
			{
				if (Remotecon[j - '0']) //ã����
				{
					//����
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
					
					for (i = i + 1; i < Nstr.size(); i++) // �����ڸ� ���ں���
					{
						MostNearNumBigger[i] = SmallestNum + '0';
					}

					break; //������ Ż��
				}
			}
		}
	}

	//���� ���� ���������ε� �����
	std::string MostNearNumSmaller;
	MostNearNumSmaller.resize(Nstr.size(), 'N');

	for (int i = 0; i < Nstr.size(); ++i)
	{
		if (Remotecon[Nstr[i] - '0']) // ������ ���ڸ�
		{
			MostNearNumSmaller[i] = Nstr[i];
			continue; //��Ƽ��
		}
		else
		{
			//�Ұ����� ���ڸ�
			for (char j = Nstr[i] - 1; j >= '0'; j--) // ���� ����� �������� ã��
			{
				if (Remotecon[j - '0'] || (i == 0 && j == '0')) //ã����
				{
					//����
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

					for (i = i + 1; i < Nstr.size(); i++) // �����ڸ� ���ں���
					{
						MostNearNumSmaller[i] = BigestNum + '0';
					}

					break; //������ Ż��
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
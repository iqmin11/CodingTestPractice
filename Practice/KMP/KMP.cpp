#include <iostream>
#include <vector>

std::vector<std::string> GetPrefix(const std::string& Str)
{
	std::vector<std::string> Prefix;
	Prefix.reserve(Str.size());
	for (size_t i = 0; i < Str.size(); i++)
	{
		std::string Temp = std::string();
		if (i == 0)
		{
			Temp = Str[0];
			Prefix.push_back(Temp);
			continue;
		}

		Temp = Prefix[i - 1] + Str[i];
		Prefix.push_back(Temp);
	}

	return Prefix;
}

std::vector<std::string> GetSuffix(const std::string& Str)
{
	std::vector<std::string> Suffix;
	Suffix.reserve(Str.size());
	for (size_t i = Str.size(); i > 0; i--)
	{
		std::string Temp = std::string();

		for (size_t j = i - 1; j < Str.size(); j++)
		{
			Temp += Str[j];
		}
		Suffix.push_back(Temp);
	}

	return Suffix;
}


//�־��� ���ڿ��� ���� �κй��ڿ����� Prefix == Suffix�� �� �� �ִ� �κ� ���ڿ� �� ���� ����� ����
//https://bowbowbow.tistory.com/6

std::vector<int> GetPiArr(const std::string& Str)
{
	std::vector<int> PiArr;
	PiArr.resize(Str.size());

	std::vector<std::string> PartialStr = GetPrefix(Str);
	for (size_t i = 0; i < PartialStr.size(); i++)
	{
		std::vector<std::string> Prefix = GetPrefix(PartialStr[i]);
		Prefix.pop_back();//�ڱ��ڽ��� �������� �ʱ� ������ ������ ex) ���ڿ� AB���� AB�� ���°�
		std::vector<std::string> Suffix = GetSuffix(PartialStr[i]);
		Suffix.pop_back();//��������

		int MaxLenth = 0;

		for (size_t j = 0; j < Prefix.size(); j++)
		{
			if (Prefix[j] == Suffix[j])
			{
				MaxLenth = j + 1;
			}
		}

		PiArr[i] = MaxLenth;
	}

	return PiArr;
}


std::vector<int> KMP(const std::string& Str, const std::string& FindStr)
{
	std::vector<int> Result; //FindStr�� ���Index���� �ִ� ����

	size_t n = Str.size();
	size_t m = FindStr.size();
	size_t j = 0;

	//����Ž���� ���� ��ȿ������ ���
	//for (size_t i = 0; i < n; i++)
	//{
	//	//���ڿ� ��
	//	while (j > 0 && Str[i] != FindStr[j]) //�ٸ���
	//	{
	//		j = 0;
	//	}

	//	if (Str[i] == FindStr[j]) // ��ġ�߰�
	//	{
	//		if (j == m - 1) //���������ڱ��� üũ �ߴٸ�
	//		{
	//			Result.push_back(i - m + 1); //Str���� FindStr�� ���ڿ��� ���� �ε��� �߰�
	//		}
	//		else
	//		{
	//			j++; //�������� üũ
	//		}
	//	}
	//}

	//����Ž������ Pi�迭�� Ȱ���Ͽ� �ǳʶۼ� �ִ� index�� �ľ� ����
	std::vector<int> PiArr = GetPiArr(FindStr);
	for (size_t i = 0; i < n; i++)
	{
		//���ڿ� ��
		while (j > 0 && Str[i] != FindStr[j]) //�ٸ���
		{
			j = PiArr[j - 1]; // j-1�� üũ�ϸ鼭 ��ġ�Ѱ� ������ �ε���
		}

		if (Str[i] == FindStr[j]) // ��ġ�߰�
		{
			if (j == m - 1) //���������ڱ��� üũ �ߴٸ�
			{
				Result.push_back(i - m + 1); //Str���� FindStr�� ���ڿ��� ���� �ε��� �߰�
				j = PiArr[j]; //��ġ�Ѱ������� �ε���
			}
			else
			{
				j++; //�������� üũ
			}
		}
	}

	return Result;
}


int main()
{
	//�־��� ���ڿ�
	std::string Str = "abcabcabc";

	//ã���� �ϴ� ���ڿ�
	std::string FindStr = "abcabc";
	
	std::vector<int> Answer = KMP(Str, FindStr);

	int a = 0;
}
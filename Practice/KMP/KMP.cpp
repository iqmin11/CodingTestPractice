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


//주어진 문자열의 접두 부분문자열에서 Prefix == Suffix가 될 수 있는 부분 문자열 중 가장 긴것의 길이
//https://bowbowbow.tistory.com/6

std::vector<int> GetPiArr(const std::string& Str)
{
	std::vector<int> PiArr;
	PiArr.resize(Str.size());

	std::vector<std::string> PartialStr = GetPrefix(Str);
	for (size_t i = 0; i < PartialStr.size(); i++)
	{
		std::vector<std::string> Prefix = GetPrefix(PartialStr[i]);
		Prefix.pop_back();//자기자신은 포함하지 않기 때문에 빼줬음 ex) 문자열 AB에서 AB는 빼는것
		std::vector<std::string> Suffix = GetSuffix(PartialStr[i]);
		Suffix.pop_back();//마찬가지

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
	std::vector<int> Result; //FindStr이 어디Index부터 있다 모음

	size_t n = Str.size();
	size_t m = FindStr.size();
	size_t j = 0;

	//완전탐색을 통한 비효율적인 방법
	//for (size_t i = 0; i < n; i++)
	//{
	//	//문자열 비교
	//	while (j > 0 && Str[i] != FindStr[j]) //다르면
	//	{
	//		j = 0;
	//	}

	//	if (Str[i] == FindStr[j]) // 일치했고
	//	{
	//		if (j == m - 1) //마지막글자까지 체크 했다면
	//		{
	//			Result.push_back(i - m + 1); //Str에서 FindStr의 문자열의 시작 인덱스 추가
	//		}
	//		else
	//		{
	//			j++; //다음글자 체크
	//		}
	//	}
	//}

	//완전탐색에서 Pi배열을 활용하여 건너뛸수 있는 index를 파악 가능
	std::vector<int> PiArr = GetPiArr(FindStr);
	for (size_t i = 0; i < n; i++)
	{
		//문자열 비교
		while (j > 0 && Str[i] != FindStr[j]) //다르면
		{
			j = PiArr[j - 1]; // j-1은 체크하면서 일치한곳 까지의 인덱스
		}

		if (Str[i] == FindStr[j]) // 일치했고
		{
			if (j == m - 1) //마지막글자까지 체크 했다면
			{
				Result.push_back(i - m + 1); //Str에서 FindStr의 문자열의 시작 인덱스 추가
				j = PiArr[j]; //일치한곳까지의 인덱스
			}
			else
			{
				j++; //다음글자 체크
			}
		}
	}

	return Result;
}


int main()
{
	//주어진 문자열
	std::string Str = "abcabcabc";

	//찾고자 하는 문자열
	std::string FindStr = "abcabc";
	
	std::vector<int> Answer = KMP(Str, FindStr);

	int a = 0;
}
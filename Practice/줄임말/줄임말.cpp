//���� �ּ� : https://www.biko.kr/problem/1694

#include <iostream>
#include <sstream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	//cin cout�� �ѱ�� ������ �ʰ� �ϱ� ���� ��ġ
	std::wcin.imbue(std::locale("korean"));
	std::wcout.imbue(std::locale("korean"));

	//�ܼ��� cin >> �����ڷ� ���� ��, \n�� �����󱸿�, �׷��� �ƾ� getline���� �޾ƹ���
	//�ѱ�� ����ϱ����� �ڷ��� wstring, �⺻������ wchar_t�� ��
	std::wstring NStr;
	std::getline(std::wcin, NStr);

	int N = std::stoi(NStr); // N���� ��ȯ

	std::vector<std::wstring> Answer;

	Answer.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::wstring Str;
		
		std::getline(std::wcin, Str);

		std::wstringstream Buffer(Str);

		std::wstring temp;
		
		while (Buffer >> temp)
		{
			Answer[i].push_back(temp[0]);
		}
	}

	std::wcout << std::endl;

	for (auto& i : Answer)
	{
		std::wcout << i << std::endl;
	}
	
	return 0;
}
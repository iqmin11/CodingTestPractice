#include <iostream>
#include <string>
#include <sstream>

int main()
{
	//cin cout�� �ѱ�� ������ �ʰ� �ϱ� ���� ��ġ
	std::wcin.imbue(std::locale("korean"));
	std::wcout.imbue(std::locale("korean"));

	//�ѱ�� ����ϱ����� �ڷ��� wstring, �⺻������ wchar_t�� ��
	std::wstring WStr;

	//wstr�� stringstream, �Ȱ��� ��� ����
	std::wstringstream WSS; 

	//wstr��  cin, cout
	std::wcin;
	std::wcout;

	return 0;
}
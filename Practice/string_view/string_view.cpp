#include <iostream>
#include <string_view>

std::string StrTest(std::string_view _value)
{
	return _value.data();
}

std::string StrWrong(const std::string& _value)
{
	return _value.data();
}

int main()
{
	std::string_view Strview = "asdasdasdasdsa"; //� ������ ���ڿ� �����͸� �޾Ƶ�, ������ ����ü�� ���� �ִ°� �ƴ϶� �Է��� ���� �����ͷ� ����ų��
	
	int strviewSize = sizeof(Strview); //ũ�� 16byte�� �ڷ���
	//8byte�� const char*(���ڿ� ������, const�̱� ������ ���ڿ� ���ͷ��� ���� �� �ִ°�), 8byte�� unsigned __int64 (���ڿ��� size ����)

	std::string Str = Strview.data(); //�̷� ��쿡�� �翬�ϰ� str�� �����ϰ���

	char cstyle[10] = "what"; //c��Ÿ�� ���ڿ�
	
	//��Ʈ�� �並 ����ϴ�����
	Str = StrTest("asdas"); //���ڿ� ���ͷ�
	Str = StrTest(cstyle); //c��Ÿ�� ���ڿ�(char*)
	Str = StrTest(Str); //std::stirng
	//� ������ ���ڿ��� ���ڷ� �޾Ƶ� ��������� �Ͼ�� ����(�����Ҵ��� �Ͼ�� �ʴ´ٴ� �Ҹ�)

	//�ݸ� string&�� ����ϴ� ���
	Str = StrWrong("asdas"); //���ڿ� ���ͷ� : ������� �Ͼ(std::string("asdas"))
	Str = StrWrong(cstyle); //c��Ÿ�� ���ڿ� : ������� �Ͼ(std::string(cstyle))
	Str = StrWrong(Str); //������� �Ͼ�� ���� �翬�� ����

	//�̷� ������ string_view�� ���ϴ�.
}
#include <iostream>
#include <vector>

int main()
{
	//�����͸� ���� ������
	int intData = 12345;
	//4����Ʈ 2������ ǥ���ϸ�
	//00000000 00000000 00110000 00111001��
	//��Ʈ������ Ȯ���ϸ�
	//00111001 00110000 00000000 00000000��
	//�ں��� ����Ǵ°��� �� �� ����
	//��Ʋ����� ������� �����Ͱ� �����

	//Buffer�� �����͸� ������ char �迭
	//������ int�� 4byte�ϱ� �� char 4��¥���� ������
	std::vector<char> Buffer(4,0);

	//���ۿ� IntData�� ��������
	memcpy_s(Buffer.data(), sizeof(intData), &intData, sizeof(intData));

	//����� ����
	//[57][48][0][0]�� ����� �̰� Serialize�� ���� �⺻�̶�� �� ���ְڴ�.
	//�� � �����͸� ����Ʈ ���� ���۷� �ɰ� �����ϴ°��� ����ȭ
	//��Ʈ������ Ȯ���ϸ�
	//00111001 00110000 00000000 00000000

	//�׷� �׷� ������ȭ��?
	//Buffer�ȿ� �����͸� �ٽ� int�� �ٲ㺸��

	//�����͸� ���� ��
	int ReadData = 0;
	memcpy_s(&ReadData, sizeof(int), Buffer.data(), Buffer.size() * sizeof(char));
	
	//����� ����
	// *ReadData == 12345
	//�˸´� �ڷ����� �˸��� ũ���� �����͸� �����ϱ⸸ �ϸ�, �ش� ��Ʈ���� �ؼ��ϴ°� �ڷ����� ��
	//�� ���ɴϴ�


	//�̹����� ��Ʈ���� ����ȭ �غ���
	std::string StrData = "I am Hwang Seung-Min.";
	
	//string�� �迭���̱� ������ �������� ũ�Ⱑ �������ִ� �ڷ����� �ƴϴ�
	//������ string�� ���̸� �˾ƾ��Ѵ�.
	//�׷��� ������ȭ�� �Ҷ�, ���̿� ���� �����͸� ���� �� �ִ�
	size_t StrDataLen = StrData.size();
	
	//�׷� �ΰ��� �����͸� �����ؾ��Ѵ�, �ϳ��� string�� ����, �ٸ� �ϳ��� str������ �� ��ü
	//�׸�ŭ �̻��� ���� ũ�Ⱑ �ʿ��ϰ���? ���� ����ؼ� �����ô�
	Buffer.resize(sizeof(size_t) + StrDataLen * sizeof(char) + 1); // �ǵ� \0�� �����ϱ� �ߴµ� ��...

	//���ۿ� StrDataLen�� ���� ��������
	memcpy_s(Buffer.data(), sizeof(size_t), &StrDataLen, sizeof(size_t));

	//StrData�� �� ���� ��ġ���� �־�߰ڳ׿�
	memcpy_s(Buffer.data() + sizeof(size_t), StrDataLen * sizeof(char), StrData.data(), StrDataLen * sizeof(char));

	//����� �ѹ� ���ô�
	//8����Ʈ�� StrDataLen��, �׵� ����Ʈ���� StrData�� �� ����.

	//�̹����ٽ� ������ȭ
	std::string ReadStr;
	size_t ReadLen = 0;
	memcpy_s(&ReadLen, sizeof(size_t), Buffer.data(), sizeof(size_t));
	ReadStr.resize(ReadLen); //�����͸� �о���� �޸𸮸� �̸� Ȯ��
	memcpy_s(ReadStr.data(), ReadLen * sizeof(char), Buffer.data() + sizeof(ReadLen), ReadLen * sizeof(char));
	
	//����� ����
	//�� ���´�
	//�����͸� ���� ��ġ�� Offset���� ����� ����ȭ�ϸ� �� ���ϰ� �� �� �ִ�.
	//�ּҰ��̳� �����Ϸ� ��縶�� �ڷ��� ũ�Ⱑ �޶��� �� �ִ� �ڷ������� �̷����� ����ȭ�� ��� ������ �� �ִ�.
	//������ size_t�� ����ȭ �ϴ°͵� ���������� __int32 �̷� �ڷ����� ���°��� ������ �� �ֽ��ϴ�.
}

class A
{
public:
	void Test() const //�ش� �Լ��� ��ü�� �Ӽ��� �ٲ� �� ����
	{
		return;
	}

	int a = 0;
};

int main()
{
	int* Test = new int;
	const int* A = Test; //�����Ͱ� ����Ű�� �޸� ���� ���ȭ
	//*A = 8; //�Ұ���
	A = nullptr; // �����Ͱ� ����Ű�� �ּҸ� �ٲٴ� ���� ����
	
	int* const B = Test; //�����Ͱ� ����Ű�� �ּҸ� ���ȭ
	*B = 8; // �����Ͱ� ����Ű�� �޸� ���� �ٲٴ� ���� ����
	//B = nullptr; //�Ұ���

	const int* const C = Test; //�ּҿ� �� �Ѵ� ���ȭ
	//*C = 8; //�Ұ���
	//C = nullptr; //�Ұ���

	return 0;
}
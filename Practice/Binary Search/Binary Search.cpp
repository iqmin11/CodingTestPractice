#include <iostream>

int main()
{
	//0 ~ INT16_MAX �������� Ư�� ���� ã��

	int left = 0;
	int right = INT16_MAX;
	int FindValue = 36783;
	int mid = 0;

	while (left <= right)
	{
		mid = (right + left) / 2;

		if (mid == FindValue) //ã�� ���ڰ� �´ٸ�
		{
			std::cout << "ã�ҽ��ϴ�!" << mid;
			break;
		}
		else if (mid < FindValue) // mid�� �۴ٸ�
		{
			//�� ũ��
			left = mid + 1;
		}
		else if (mid > FindValue) // mid�� ũ�ٸ�
		{
			//�� �۰�
			right = mid - 1;
		}
	}

	return 0;
}
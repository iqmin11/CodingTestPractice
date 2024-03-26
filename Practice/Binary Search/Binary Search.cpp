#include <iostream>

int main()
{
	//0 ~ INT16_MAX 범위에서 특정 숫자 찾기

	int left = 0;
	int right = INT16_MAX;
	int FindValue = 36783;
	int mid = 0;

	while (left <= right)
	{
		mid = (right + left) / 2;

		if (mid == FindValue) //찾는 숫자가 맞다면
		{
			std::cout << "찾았습니다!" << mid;
			break;
		}
		else if (mid < FindValue) // mid가 작다면
		{
			//더 크게
			left = mid + 1;
		}
		else if (mid > FindValue) // mid가 크다면
		{
			//더 작게
			right = mid - 1;
		}
	}

	return 0;
}
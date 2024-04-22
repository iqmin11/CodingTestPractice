//https://www.acmicpc.net/problem/2170

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<std::pair<int, bool>> Lines; //��ġ, ������? ����?
	Lines.resize(N * 2);

	for (int i = 0; i < N * 2; i++)
	{
		std::cin >> Lines[i].first;

		if (i % 2 == 0)
		{
			Lines[i].second = false; //�������� false
		}
		else
		{
			Lines[i].second = true; //������ true
		}
	}

	std::sort(Lines.begin(), Lines.end()); //�̷��� �������ص�
	//�������� ������ ������ ������ �׳� �ϳ��� �������� ó���� �� �ִ�
	//���� �� ���� �̾��������� �ٸ� �������� ó���� �Ϸ��� �Ѵٸ�, �������� true ������ false�� �ϸ� �ȴ�

	int CurLineCount = 0;
	int CurLineStart = INT32_MAX;
	int CurLineEnd = INT32_MIN;
	int LineLength = 0;

	for (int i = 0; i < N*2; i++)
	{
		int PrevLineCount = CurLineCount;

		if (Lines[i].second == false)
		{
			CurLineCount++;
		}
		else
		{
			CurLineCount--;
		}
		
		if (CurLineCount == 1 && PrevLineCount == 0)
		{
			//���� ��°� ����
			CurLineStart = Lines[i].first;
		}
		else if (CurLineCount == 0 && PrevLineCount == 1)
		{
			//���� ��°� ����
			CurLineEnd = Lines[i].first;
			LineLength += CurLineEnd - CurLineStart;
		}
	}

	std::cout << LineLength;

	return 0;
}
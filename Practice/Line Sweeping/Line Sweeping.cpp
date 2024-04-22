#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, bool>> Lines; //���� ��ġ, ������? ����?
//�������� false, ������ true
//�������� ������ ������ ������ �׳� �ϳ��� �������� ó���� �� �ִ�
//���� �� ���� �̾��������� �ٸ� �������� ó���� �Ϸ��� �Ѵٸ�, �������� true ������ false�� �ϸ� �ȴ�

//�ݵ�� Lines�� ���ĵǾ��־���Ѵ�!!!!!!!!!!!!!!!!!!!!!!!!!

void LineSweeping()
{
	std::sort(Lines.begin(), Lines.end());

	int CurLineCount = 0;
	int CurLineStart = INT32_MAX;
	int CurLineEnd = INT32_MIN;
	int Answer = 0;

	for (int i = 0; i < Lines.size(); i++)
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
			//Line�� ����
			CurLineStart = Lines[i].first;
		}
		else if (CurLineCount == 0 && PrevLineCount == 1)
		{
			//Line�� ��
			CurLineEnd = Lines[i].first;
			
			//���⼭ �ϰ��� �ϴ� ���� �� ��
			//���� ������ ���ٴ���
			//���� ���̸� ���Ѵٴ��� ��...
		}
	}
}

int main()
{

}
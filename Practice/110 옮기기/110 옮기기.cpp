//���� �ּ� : 

#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<string> solution(vector<string> s)
{
	std::string& CurStr = s[0];

	//�����̵� ������� �տ� ���� ������ ���ڿ��� ���� üũ

	int StrSize = static_cast<int>(s.size());
	int Right = 0;
	int WindowSize = 3;
	int OneCount = 0;
	std::deque<char> Window;

	for (int Left = 0; Left < StrSize - WindowSize + 1; Left++)
	{
		while (Window.size() < WindowSize && Right < StrSize)
		{
			char PushChar = CurStr[Right];

			Window.push_back(PushChar);
			if (PushChar == '1')
			{
				OneCount++;
			}
			
			Right++;
		}

		if (OneCount == 3) 
		{
			// 111�� ���
		}
		else if (OneCount == 2 && Window.back() == '0') 
		{
			// 110�� ���
		}
		
		char PopChar = Window.front();
		if (PopChar == '1')
		{
			OneCount--;
		}

		Window.pop_front();
	}


    return s;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    solution({ "1100111011101001" });
	return 0;
}
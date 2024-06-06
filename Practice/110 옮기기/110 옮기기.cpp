//문제 주소 : 

#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<string> solution(vector<string> s)
{
	std::string& CurStr = s[0];

	//슬라이딩 윈도우로 앞에 들어온 세개의 문자열이 뭔지 체크

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
			// 111인 경우
		}
		else if (OneCount == 2 && Window.back() == '0') 
		{
			// 110인 경우
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
//���� �ּ� : https://school.programmers.co.kr/learn/courses/30/lessons/12904

#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool IsPalindrome(const std::deque<char>& CheckStr)
{
    int CheckSize = (static_cast<int>(CheckStr.size()) + 1) / 2;
    auto FrontIter = CheckStr.begin();
    auto BackIter = CheckStr.rbegin();

    for (int i = 0; i < CheckSize; i++)
    {
        if (*FrontIter++ != *BackIter++)
        {
            return false;
        }
    }

    return true;
}

int solution(string s)
{
    //���� �� �縰���
    //���̰� N�� �����̵� �����츦 �����
    //������ �ȿ� ����ִ� ���ڿ��� �Ӹ���������� �˻��ϱ�

    int StrSize = static_cast<int>(s.size());
    int WindowSize = StrSize;

    while (WindowSize > 1)
    {
        int Right = 0;
        std::deque<char> Window;

        for (int Left = 0; Left < StrSize - WindowSize + 1; ++Left)
        {
            while (Window.size() < WindowSize && Right < StrSize)
            {
                Window.push_back(s[Right]);
                Right++;
            }

            if (IsPalindrome(Window))
            {
                return WindowSize;
            }

            Window.pop_front();
        }

        --WindowSize;
    }

    return 1;
}
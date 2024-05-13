//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/12951

#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s)
{
    char PrevChar = ' ';
    for (int i = 0; i < s.size(); i++)
    {
        if (PrevChar == ' ')
        {
            s[i] = std::toupper(s[i]);
        }
        else
        {
            s[i] = std::tolower(s[i]);
        }
        PrevChar = s[i];
    }

    return s;
}
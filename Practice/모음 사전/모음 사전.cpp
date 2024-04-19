//https://school.programmers.co.kr/learn/courses/30/lessons/84512

#include <string>
#include <vector>

using namespace std;

std::string Order = "AEIOU";
std::string RecordStr = "";
int Count = 0;
int answer = 0;

void BT(int CurIndex, const std::string& DestStr)
{
    if (RecordStr == DestStr)
    {
        answer = Count;
        return;
    }

    if (RecordStr.size() == 5)
    {
        return;
    }

    for (int i = 0; i < Order.size(); ++i)
    {
        ++Count;
        RecordStr.push_back(Order[i]);
        BT(CurIndex + 1, DestStr);
        RecordStr.pop_back();
    }
}

int solution(string word)
{
    BT(0, word);
    return answer;
}
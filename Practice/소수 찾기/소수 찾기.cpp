//https://school.programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <cmath>

using namespace std;

bool IsPrime(const std::string& Buffer)
{
    int Check = std::stoi(Buffer);

    if (Check == 1)
    {
        return false;
    }

    int sq = static_cast<int>(std::sqrt(Check));
    for (int i = 2; i <= sq; i++)
    {
        if (Check % i == 0)
        {
            return false;
        }
    }
    return true;
}

std::map<char, int> IsVisit;
std::set<std::string> IsVisit_Str;

std::string Record;
int answer = 0;
void BT(const std::string& numbers)
{
    IsVisit_Str.insert(Record);

    if (Record.size() > 0)
    {
        if (IsPrime(Record))//현재 체크하는 수가 소수라면
        {
            ++answer;
        }
    }

    if (numbers.size() == Record.size())
    {
        return;
    }

    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] == '0' && Record.size() == 0)
        {
            continue;
        }

        if (IsVisit[numbers[i]] == 0)
        {
            continue;
        }

        std::string Check = Record;
        Check.push_back(numbers[i]);

        if (IsVisit_Str.find(Check) != IsVisit_Str.end())
        {
            continue;
        }

        IsVisit[numbers[i]] -= 1;
        Record.push_back(numbers[i]);
        BT(numbers);
        Record.pop_back();
        IsVisit[numbers[i]] += 1;
    }
}

int solution(string numbers)
{
    for (int i = 0; i < numbers.size(); ++i)
    {
        IsVisit[numbers[i]] += 1;
    }

    BT(numbers);
    return answer;
}
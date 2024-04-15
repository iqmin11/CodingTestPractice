//https://school.programmers.co.kr/learn/courses/30/lessons/132265

#include <string>
#include <vector>
#include <map>

using namespace std;
std::map<int, int> ToppingCount_A; //어떤 토핑이 몇개
std::map<int, int> ToppingCount_B;

int solution(vector<int> topping)
{
    for (int i = 0; i < topping.size(); ++i)
    {
        ToppingCount_B[topping[i]] += 1;
    }

    int right = 0;
    int CommonCaseCount = 0;

    while (right < topping.size())
    {
        ToppingCount_A[topping[right]] += 1;
        ToppingCount_B[topping[right]] -= 1;
        if (ToppingCount_B[topping[right]] == 0)
        {
            ToppingCount_B.erase(topping[right]);
        }

        if (ToppingCount_A.size() == ToppingCount_B.size())
        {
            CommonCaseCount++;
        }

        right++;
    }

    return CommonCaseCount;
}
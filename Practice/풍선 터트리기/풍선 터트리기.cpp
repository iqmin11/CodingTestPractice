//https://school.programmers.co.kr/learn/courses/30/lessons/68646

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a)
{
    std::vector<std::pair<int, int>> Data;// �ش� �ε��� ��ĭ �������� �ּҰ�, �ش� �ε��� ��ĭ �ı����� �ּҰ�;
    Data.resize(a.size());

    int MinValueLeft = INT32_MAX;
    Data[0].first = INT32_MAX;
    for (int i = 0; i < Data.size(); ++i)
    {
        if (i - 1 < 0)
        {
            continue;
        }

        MinValueLeft = std::min(MinValueLeft, a[i - 1]);
        Data[i].first = MinValueLeft;
    }

    int MinValueRight = INT32_MAX;
    Data.back().second = INT32_MAX;
    for (int i = Data.size() - 1; i >= 0; --i)
    {
        if (i + 1 >= Data.size())
        {
            continue;
        }

        MinValueRight = std::min(MinValueRight, a[i + 1]);
        Data[i].second = MinValueRight;
    }

    int answer = 0;

    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] > Data[i].first && a[i] > Data[i].second)
        {
            continue;
        }

        ++answer;
    }

    return answer; //�ð����⵵ 3n;
}
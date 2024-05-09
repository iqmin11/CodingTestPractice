//���� �ּ� : https://school.programmers.co.kr/learn/courses/30/lessons/64065

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(string s)
{
    int N = 0; // ������ ����

    std::map<int, int> DataInfo; //� ���ڰ� � �ִ��� üũ

    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] == '{')
        {
            //�� �κ������� �ϼ��Ǵ°�
            while (s[i] != '}')
            {
                i++;
                std::string Num;
                while (s[i] != ',' && s[i] != '}')
                {
                    Num.push_back(s[i]);
                    i++;
                }
                DataInfo[std::stoi(Num)]++;
            }
        }
    }

    std::vector<std::pair<int, int>> SortArr;
    for (auto i = DataInfo.begin(); i != DataInfo.end(); ++i)
    {
        SortArr.push_back(std::make_pair(i->first, i->second));
    }

    std::sort(SortArr.begin(), SortArr.end(), [](std::pair<int, int> Left, std::pair<int, int> Right)
        {
            return Left.second > Right.second;
        });

    vector<int> answer;
    for (auto& i : SortArr)
    {
        answer.push_back(i.first);
    }

    return answer;
}
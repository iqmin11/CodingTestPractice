//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/49993

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    std::vector<bool> AsciiTable;
    AsciiTable.resize(26, false);
    for (int i = 0; i < skill.size(); ++i)
    {
        AsciiTable[skill[i] - 'A'] = true;
    }

    int answer = 0;

    for (int i = 0; i < skill_trees.size(); ++i)
    {
        int CurCheckSkillIndex = 0;
        bool IsPossible = true;
        for (int j = 0; j < skill_trees[i].size(); ++j)
        {
            if (AsciiTable[skill_trees[i][j] - 'A'] == false)
            {
                continue;
            }

            if (skill[CurCheckSkillIndex] != skill_trees[i][j])
            {
                IsPossible = false;
                break;
            }

            CurCheckSkillIndex++;
        }

        if (IsPossible)
        {
            answer++;
        }
    }

    return answer;
}
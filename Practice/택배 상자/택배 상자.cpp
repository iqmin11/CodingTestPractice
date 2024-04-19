//https://school.programmers.co.kr/learn/courses/30/lessons/131704

#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> order)
{
    std::queue<int> Main;
    std::stack<int> Sub;
    for (int i = 0; i < order.size(); ++i)
    {
        Main.push(i + 1);
    }

    int CurIndex = 0;
    while (!Main.empty() || !Sub.empty())
    {
        if (!Main.empty() && Sub.empty())
        {
            int CheckMain = Main.front();
            Main.pop();

            if (CheckMain == order[CurIndex])
            {
                CurIndex++;
            }
            else
            {
                Sub.push(CheckMain);
            }
        }
        else if (!Main.empty() && !Sub.empty())
        {
            int CheckMain = Main.front();
            int CheckSub = Sub.top();

            if (CheckMain == order[CurIndex])
            {
                Main.pop();
                CurIndex++;
            }
            else if (CheckSub == order[CurIndex])
            {
                Sub.pop();
                CurIndex++;
            }
            else
            {
                Main.pop();
                Sub.push(CheckMain);
            }
        }
        else if (Main.empty() && !Sub.empty())
        {
            int CheckSub = Sub.top();
            Sub.pop();

            if (CheckSub == order[CurIndex])
            {
                CurIndex++;
            }
            else
            {
                return CurIndex;
            }
        }
    }

    return CurIndex;
}
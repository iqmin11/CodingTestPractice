//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42628

#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

std::multiset<int> pq;

void insert(int Num)
{
    pq.insert(Num);
}

void PopBack()
{
    if (pq.empty())
    {
        return;
    }

    auto EndIter = pq.end();
    pq.erase(--EndIter);
}

void PopFront()
{
    if (pq.empty())
    {
        return;
    }

    pq.erase(pq.begin());
}

vector<int> solution(vector<string> operations)
{
    for (int i = 0; i < operations.size(); i++)
    {
        std::stringstream Buffer(operations[i]);
        char Cmd;
        int Value;

        Buffer >> Cmd;
        Buffer >> Value;

        if (Cmd == 'D')
        {
            if (Value == -1)
            {
                PopFront();
            }
            else if (Value == 1)
            {
                PopBack();
            }
        }
        else if (Cmd == 'I')
        {
            insert(Value);
        }
    }

    if (pq.empty())
    {
        return { 0,0 };
    }

    vector<int> answer;

    auto EndIter = pq.end();

    answer.push_back(*(--EndIter));
    answer.push_back(*pq.begin());

    return answer;
}

int main()
{
    solution({"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"});

    return 0;
}
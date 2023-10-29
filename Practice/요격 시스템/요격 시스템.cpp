#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

//자료를 최대한 자료 그대로 쓰는 연습을 하자

class A
{
public:
    int Pos = -1;
    int Value = -99;
    A* Pair = nullptr;
};

int solution(vector<vector<int>> targets)
{
    std::vector<A*> Attacks = std::vector<A*>();

    for (size_t i = 0; i < targets.size(); i++)
    {
        A* Temp0 = new A();
        Temp0->Pos = targets[i][0];
        Temp0->Value = 1;

        A* Temp1 = new A();
        Temp1->Pos = targets[i][1];
        Temp1->Value = -1;

        Attacks.push_back(Temp0);
        Attacks.push_back(Temp1);

        Temp0->Pair = Temp1;
        Temp1->Pair = Temp0;
    }


    std::sort(Attacks.begin(), Attacks.end(), [](A* _left, A* _right) 
        { 
            if (_left->Pos == _right->Pos)
            {
                return _left->Value < _right->Value;
            }
       
            return _left->Pos < _right->Pos ;
        });

    std::list<A*> Temp = std::list<A*>();
    int count = 0;

    for (auto& i : Attacks)
    {
        Temp.push_back(i);
        if (i->Value == -1)
        {
            for (auto& j : Temp)
            {
                j->Pair->Value = 1;
            }
            count++;
            Temp.clear();
        }
    }

    return count;
}

int main()
{
    solution({ {4, 5} ,{4, 8},{10, 14},{11, 13},{5, 12},{3, 7},{1, 4} });
    return 0;
}
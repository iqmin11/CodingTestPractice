#include <iostream>
#include <string>
#include <vector>

using namespace std;

//하노이의 탑 n개를 옮기는 방법
//n-1개를 목적지가 아닌곳에 놓음
//가장 밑에 큰 원판을 목적지에 놓음
//n-1개를 목적지에 놓음

vector<vector<int>> HanoiAlgorithm(int _Start, int _Destination, int _n)
{
    int NoDestination = 0;
    vector<vector<int>> result;
    vector<vector<int>> Addresult;

    if (_Start == 2 && _Destination == 3 || _Start == 3 && _Destination == 2)
    {
        NoDestination = 1;
    }
    else if (_Start == 1 && _Destination == 3 || _Start == 3 && _Destination == 1)
    {
        NoDestination = 2;
    }
    else
    {
        NoDestination = 3;
    }


    if (_n > 0)
    {
        result = HanoiAlgorithm(_Start, NoDestination, _n - 1);
        result.push_back({ _Start,_Destination });
        Addresult = HanoiAlgorithm(NoDestination, _Destination, _n - 1);
        for (int i = 0; i < Addresult.size(); i++)
        {
            result.push_back(Addresult[i]);
        }
    }

    return result;
}

vector<vector<int>> solution(int n) {
    return HanoiAlgorithm(1, 3, n);
}

int main()
{
    vector<vector<int>> Answer;
    Answer = HanoiAlgorithm(1, 3, 2);
}

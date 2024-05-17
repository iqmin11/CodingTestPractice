#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> Arr;

int Func(int _Start, int _End, int _Index)
{
    std::vector<int> v;
    v.reserve(_End - _Start + 1);
    int StartIndex = _Start - 1;
    int EndIndex = _End - 1;
    for (int i = StartIndex; i <= EndIndex; i++)
    {
        v.push_back(Arr[i]);
    }

    std::sort(v.begin(), v.end());
    return v[_Index - 1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    Arr = array;
    vector<int> answer;
    answer.reserve(commands.size());

    for (int i = 0; i < commands.size(); i++)
    {
        int Start = commands[i][0];
        int End = commands[i][1];
        int Index = commands[i][2];
        answer.push_back(Func(Start, End, Index));
    }
    return answer;
}
//https://school.programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    std::queue<std::pair<int, int>> MoveTruck; //����, �����ð�

    int CurIndex = 0;
    int CurWeight = 0;
    int Time = 0;
    int answer = 0;

    while (CurIndex < truck_weights.size() || !MoveTruck.empty())
    {
        ++Time;

        //�������°� ����Ǿ����
        if (!MoveTruck.empty())
        {
            if (MoveTruck.front().second == Time)
            {
                //������
                CurWeight -= MoveTruck.front().first;
                MoveTruck.pop();
            }
        }

        if (CurIndex < truck_weights.size())
        {
            if (MoveTruck.size() <= bridge_length && CurWeight + truck_weights[CurIndex] <= weight)
            {
                //�ö�
                CurWeight += truck_weights[CurIndex];
                //�����ð��� ��߽ð� + �ٸ� ����
                MoveTruck.push({ truck_weights[CurIndex], Time + bridge_length });
                CurIndex++;
            }
        }
    }

    return Time;
}
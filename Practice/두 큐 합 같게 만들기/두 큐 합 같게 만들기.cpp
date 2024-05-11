//���� �ּ� : https://school.programmers.co.kr/learn/courses/30/lessons/118667

#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

std::map<std::pair<std::pair<int, int>, std::pair<int, int>>, bool> IsVisit;

int solution(vector<int> queue1, vector<int> queue2)
{
    long long SumQ1 = 0;
    long long SumQ2 = 0;
    std::queue<std::pair<int, std::pair<int, int>>> Q1; // ��, �ε���(�ʱ� � ť�� ���°�� �ִ���)
    std::queue<std::pair<int, std::pair<int, int>>> Q2;

    for (int i = 0; i < queue1.size(); i++)
    {
        SumQ1 += queue1[i];
        Q1.push(std::make_pair(queue1[i], std::make_pair(1, i)));

        SumQ2 += queue2[i];
        Q2.push(std::make_pair(queue2[i], std::make_pair(2, i)));
    }

    int answer = 0;
    while (SumQ1 != SumQ2)
    {
        if (IsVisit[std::make_pair(Q1.front().second, Q2.front().second)])
        {
            answer = -1;
            break;
        }

        IsVisit[std::make_pair(Q1.front().second, Q2.front().second)] = true;

        //ū���� ���� ����������
        if (SumQ1 > SumQ2)
        {
            std::pair<int, std::pair<int, int>> temp = Q1.front();
            Q1.pop();
            SumQ1 -= temp.first;

            Q2.push(temp);
            SumQ2 += temp.first;

            answer++;
        }
        else if (SumQ1 < SumQ2)
        {
            std::pair<int, std::pair<int, int>> temp = Q2.front();
            Q2.pop();
            SumQ2 -= temp.first;

            Q1.push(temp);
            SumQ1 += temp.first;

            answer++;
        }
    }

    return answer;
}

//�������� �䱸�ϴ� ���α׷��� ���� ��ü�� �������� ���ѷ����� ������ ��츦 ����ó���ϴ� ���� ����� �������ٰ� ������.
//�湮üũ�� ���� �Ȱ��� ��츦 �� ���� �ʰ� üũ�ϴ� ���̵� ������
//Q�� ���¸� �ε����� ���⿡�� �ʹ� ���ſ��� �ٸ� ����� �����ؾ��ߴ�.
//�ᱹ �� ť�� ����Ʈ�� �ε����� ����� ���� ���� �ߴµ�,
//�ƽ���� ť�� Ű�� ��ü�� �ʹ� �����ϰ� ������ٴ°�. �׳� �� �ܼ��ϰ� ���� ��ȣ�� �ο��ϴ°� �������� ����

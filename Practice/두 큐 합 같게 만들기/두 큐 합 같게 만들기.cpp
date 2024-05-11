//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/118667

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
    std::queue<std::pair<int, std::pair<int, int>>> Q1; // 값, 인덱스(초기 어떤 큐에 몇번째에 있던값)
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

        //큰놈을 빼서 작은놈으로
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

//문제에서 요구하는 프로그램의 구현 자체는 쉬웠지만 무한루프에 빠지는 경우를 예외처리하는 것이 어려운 문제였다고 생각됨.
//방문체크를 통해 똑같은 경우를 또 돌지 않게 체크하는 아이디어를 냈지만
//Q의 상태를 인덱스로 쓰기에는 너무 무거워져 다른 방법을 생각해야했다.
//결국 각 큐의 프론트를 인덱스로 사용해 대응 가능 했는데,
//아쉬운건 큐의 키값 자체를 너무 복잡하게 만들었다는것. 그냥 더 단순하게 고유 번호를 부여하는게 좋았을것 같다

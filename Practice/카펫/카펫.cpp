#include <string>
#include <vector>

using namespace std;

//노란색 가로 * 세로 일때
//갈색은 노란색의 가로 + 2 * 세로 + 2
//갈색의 개수는 그러면 
vector<int> solution(int brown, int yellow)
{
    std::vector<std::pair<int, int>> MulPair;

    MulPair.reserve(yellow);

    //몇*몇 기억
    for (int i = 1; i <= yellow; i++)
    {
        int Quo = 0;
        if (yellow % i == 0) //나누어떨어질때
        {
            Quo = yellow / i; // 몇나누기 몇이야?
            if (i <= Quo)
            {
                MulPair.push_back(std::make_pair(Quo, i)); //i * quo는 yellow
            }
            else
            {
                break;
            }
        }
    }

    vector<int> answer;
    int lt = 0;
    int rt = MulPair.size() - 1;

    while (lt <= rt)
    {
        int mid = (lt + rt) / 2;
        int Check = 2 * (MulPair[mid].first + MulPair[mid].second + 2); //옐로우와 브라운의 관계
        if (Check == brown)
        {
            answer.push_back(MulPair[mid].first + 2);
            answer.push_back(MulPair[mid].second + 2);
            return answer;
        }
        else if (Check > brown)
        {
            lt = mid + 1;
            //체크가 작아져야하니 미드가 커져야함
        }
        else if (Check < brown)
        {
            rt = mid - 1;
            //체크가 커져야 하니 미드가 작아져야함
        }
    }

    return answer;
}

int main()
{
    solution(24, 24);

    return 0;
}
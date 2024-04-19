#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

    class Comp
    {
    public:
        bool operator()(const std::pair<std::string, std::string>& Left, const std::pair<std::string, std::string>& Right) const
        {
            if (Left.second == Right.second)
            {
                return Left.first < Right.first;
            }

            return Left.second < Right.second;
        }
    };

    std::map<std::pair<std::string, std::string>, bool> IsVisit;
    std::map<std::pair<std::string, std::string>, std::set<std::pair<std::string, std::string>, Comp>> LinkNodes;

    vector<string> answer;
    std::deque<std::string> RecordStack;
    bool IsFind = false;

    void DFS(const std::pair<std::string, std::string>& CurNode)
    {
        if (IsFind)
        {
            return;
        }

        IsVisit[CurNode] = true;
        RecordStack.push_back(CurNode.first);

        if (IsVisit.size() == RecordStack.size())
        {
            IsFind = true;
            for (auto& i : RecordStack)
            {
                answer.push_back(i);
            }

            answer.push_back(CurNode.second);
            return;
        }

        for (auto& LinkNode : LinkNodes[CurNode])
        {
            if (IsVisit[LinkNode])
            {
                continue;
            }

            DFS(LinkNode);
        }

        IsVisit[CurNode] = false;
        RecordStack.pop_back();
    }

    vector<string> solution(vector<vector<string>> tickets)
    {
        for (auto& i : tickets)
        {
            IsVisit[std::make_pair(i[0], i[1])] = false;

            for (auto& j : tickets)
            {
                IsVisit[std::make_pair(j[0], j[1])] = false;
                if (i[1] == j[0])
                {
                    LinkNodes[std::make_pair(i[0], i[1])].insert(std::make_pair(j[0], j[1]));
                }
            }
        }

        for (auto& i : IsVisit)
        {
            if (IsFind == false)
            {
                DFS(i.first);
            }
        }

        return answer;
    }

int main()
{
    std::vector<std::vector<std::vector<std::string>>> TestCase;
    TestCase.push_back({ {"ICN", "BOO"}, {"ICN", "COO"}, {"COO", "DOO"}, {"DOO", "COO"}, {"BOO", "DOO"}, {"DOO", "BOO"}, {"BOO", "ICN"}, {"COO", "BOO"} });
    TestCase.push_back({ {"ICN", "BOO"}, {"BOO", "COO"}, {"COO", "ICN"}, {"ICN", "BOO"}, {"BOO", "COO"}, {"COO", "ICN"} });
    TestCase.push_back({ {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"} });
    TestCase.push_back({ {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}, {"AAA", "HND"}, {"JFK", "AAA"} });
    TestCase.push_back({ {"ICN","AAA"},{"ICN","AAA"},{"ICN","AAA"},{"AAA","ICN"},{"AAA","ICN"} });
    TestCase.push_back({ {"ICN", "AAA"}, {"ICN", "BBB"}, {"BBB", "CCC"}, {"AAA", "DDD"}, {"DDD", "EEE"}, {"CCC", "ICN"} });

    auto K = solution(TestCase[0]);

    int a = 0;
}
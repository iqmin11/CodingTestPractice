#include <vector>
#include <map>
#include <queue>
#include <list>

using namespace std;

std::map<int, int> Cards;
std::priority_queue<std::pair<int, std::list<int>>> Groups;

void GameUpdate(std::list<int>& _Group, int _Select)
{
    auto FindIter = Cards.find(_Select);
    if (FindIter == Cards.end())
    {
        return;
    }
    _Group.push_back(FindIter->second);
    Cards.erase(FindIter);
    GameUpdate(_Group, _Group.back());
}

int solution(vector<int> cards)
{
    for (int i = 0; i < cards.size(); ++i)
    {
        Cards.insert(std::make_pair(i + 1, cards[i]));
    }

    while (!Cards.empty())
    {
        std::list<int> Group;
        int StartIndex = Cards.begin()->first;
        GameUpdate(Group, StartIndex);
        Groups.push(std::make_pair(static_cast<int>(Group.size()), Group));
    }
    
    int answer = 1;
    answer *= Groups.top().first;
    Groups.pop();
    if (Groups.size() == 0)
    {
        answer *= 0;
    }
    answer *= Groups.top().first;

    return answer;
}

int main()
{
    solution({ 8,6,3,7,2,5,1,4 });

    return 0;
}
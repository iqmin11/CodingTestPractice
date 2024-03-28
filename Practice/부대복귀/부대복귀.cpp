#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

std::vector<std::set<std::pair<int, int>>> LinkNodes; //LinkNodes[a] = a�� ����� ������ ������ first->���, second->������
//pair�� �� �����ڶ����� first(���) �������� ���ĵȴ�(����� ������ �ε��� ��������)

std::vector<int> DijkstraPQ(int _Start)
{
    std::vector<int> Dist; //Dist[a] = _Start���� a�� ���� �ּ� ���
    Dist.resize(LinkNodes.size(), INT32_MAX); //��� int_max�� �ʱ�ȭ
    Dist[_Start] = 0; //���������� ����� 0���� �翬��

    std::priority_queue<std::pair<int, int>> pq; //��ũ��� ������ <���, �ε���>�� �켱���� ť�� ����
    pq.push({ -Dist[_Start] , _Start });//<��� , ��ġ>�� �ִµ�, pq�� �������� �����̱⶧���� ����� �������� ���ķ� �ٲٱ� ���ؼ�
    //-������� �����ϰ�, �������� �ٽ� -�� ������ ����� ���
    while (!pq.empty())
    {
        //���� �տ��ִ¾�(pq�� ����� ��� �� �̵� ����� ���� ������)�� ���� üũ�� ���̰���?
        int CurCost = -pq.top().first; //CurNode�� ���� ��� , -�� ���ؼ� ���������� ���
        int CurIndex = pq.top().second;//CurNode�� �ε���

        pq.pop();//�b�ϰ�

        //1. Dist[CurIndex] => ���� ����� CurIndex�� ���� �ּҺ��� CurCost�� ���ؼ�
        //	Dist[CurIndex] < CurCost�� ��Ƽ��(������ via = curcost + LinkNodecost�ε� curcost�� �̹� ũ�� �Ʒ� ������ �ʿ䰡 ����)
        if (Dist[CurIndex] < CurCost)
        {
            continue;
        }

        //2. ���⼱ �ּҰ� ������ ������ ���ľ߰���?
        for (auto& LinkNode : LinkNodes[CurIndex])//���� üũ�ϴ� �ε����� ����Ǿ��ִ� ������ ���鼭
        {
            int ViaCost = CurCost + LinkNode.first;//CurNode�� �� ��� + CurNode���� LinkNode�� ���� ��� cf)via : ~�� ����
            if (Dist[LinkNode.second] > ViaCost) //���� üũ�� �ּҺ���̶� ��
            {
                Dist[LinkNode.second] = ViaCost; //via�� �� ������ ����
                pq.push({ -Dist[LinkNode.second], LinkNode.second });//�����Ҷ��ѰŶ� ����? <-��� , ��ġ>Ǫ��
            }
        }
    }

    return Dist;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    LinkNodes.resize(n);
    for (size_t i = 0; i < roads.size(); i++)
    {
        int NodeA = roads[i][0] - 1;
        int NodeB = roads[i][1] - 1;

        LinkNodes[NodeA].insert(std::make_pair(1, NodeB));
        LinkNodes[NodeB].insert(std::make_pair(1, NodeA));
    }
   std::vector<int> Result = DijkstraPQ(destination - 1);
   std::vector<int> answer;
   answer.resize(sources.size());

   for (size_t i = 0; i < sources.size(); i++)
   {
       answer[i] = Result[sources[i] - 1];
   }

    return answer;
}
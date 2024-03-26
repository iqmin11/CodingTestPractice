//https://www.acmicpc.net/problem/5021

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>

std::map<std::string, int> InDgree; //진입차수
std::map<std::string, std::set<std::string>> LinkNodes; //연결 노드
std::map<std::string, std::pair<std::string, std::string>> ParentInfo; //부모 노드
std::map<std::string, double> BloodInfo;

bool TopologySort()
{
	std::queue<std::string> q;

	for (auto i : InDgree)
	{
		if (i.second == 0)
		{
			q.push(i.first);
		}
	}

	for (size_t i = 0; i < InDgree.size(); i++)
	{
		if (q.empty())
		{
			return false;
		}

		std::string CheckIndex = q.front();
		q.pop();

		auto FindParnetIter = ParentInfo.find(CheckIndex);
		if (FindParnetIter != ParentInfo.end())
		{
			std::string& Parent0 = FindParnetIter->second.first;
			std::string& Parent1 = FindParnetIter->second.second;
			BloodInfo[CheckIndex] = (BloodInfo[Parent0] + BloodInfo[Parent1]) / 2;
		}

		for (auto& LinkNode : LinkNodes[CheckIndex])
		{
			if (--InDgree[LinkNode] == 0)
			{
				q.push(LinkNode);
			}
		}
	}

	return true;
}

struct Comp
{
	bool operator()(const std::string& _Left, const std::string& _Right)
	{
		return BloodInfo[_Left] < BloodInfo[_Right];
	}
};

int main()
{
	int N, M;
	std::cin >> N >> M;
	std::string King;
	std::cin >> King;
	BloodInfo.insert({ King , 1.0});
	InDgree.insert(std::make_pair(King, 0));

	for (size_t i = 0; i < N; i++)
	{
		std::string Child;
		std::string Parent0;
		std::string Parent1;

		std::cin >> Child >> Parent0 >> Parent1;

		InDgree.insert(std::make_pair(Child, 0));
		InDgree.insert(std::make_pair(Parent0, 0));
		InDgree.insert(std::make_pair(Parent1, 0));

		LinkNodes.insert(std::make_pair(Child, std::set<std::string>()));
		LinkNodes.insert(std::make_pair(Parent0, std::set<std::string>()));
		LinkNodes.insert(std::make_pair(Parent1, std::set<std::string>()));

		BloodInfo.insert(std::make_pair(Child, 0.0));
		BloodInfo.insert(std::make_pair(Parent0, 0.0));
		BloodInfo.insert(std::make_pair(Parent1, 0.0));

		ParentInfo.insert(std::make_pair(Child, std::make_pair(Parent0, Parent1)));

		InDgree[Child] += 2;
		LinkNodes[Parent0].insert(Child);
		LinkNodes[Parent1].insert(Child);
	}

	TopologySort();

	std::priority_queue<std::string, std::vector<std::string>, Comp> NextKingOrder;

	for (size_t i = 0; i < M; i++)
	{
		std::string NextKing;
		std::cin >> NextKing;
		NextKingOrder.push(NextKing);
	}

	std::cout << NextKingOrder.top();

	return 0;
}
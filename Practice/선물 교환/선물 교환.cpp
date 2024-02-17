#include <iostream>
#include <vector>
#include <queue>
#include <set>

int NumTwoCount = 0;

struct Comp
{
	bool operator()(const std::pair<int*, int>& _Left, const std::pair<int*, int>& _Right)
	{
		if (*(_Left.first) != *(_Right.first))
		{
			return *(_Left.first) > *(_Right.first);
		}
		else
		{
			return _Left.second > _Right.second;
		}
	}
};

bool IsFair(int _pqSize)
{
	return _pqSize == NumTwoCount;
}

int main()
{
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> GiveGift;
	std::vector<int> ReceiveGiftCount;
	std::vector<std::set<int>> ReceiveGiftMember;

	GiveGift.resize(N);
	ReceiveGiftCount.resize(N);
	ReceiveGiftMember.resize(N);


	for (int i = 0; i < N; i++)
	{
		int temp1, temp2;
		std::cin >> temp1 >> temp2;
		GiveGift[i].first = temp1 - 1;
		GiveGift[i].second = temp2 - 1;
		
		if (ReceiveGiftCount[GiveGift[i].first] == 1)
		{
			++NumTwoCount;
		}

		if (ReceiveGiftCount[GiveGift[i].second] == 1)
		{
			++NumTwoCount;
		}

		if (ReceiveGiftCount[GiveGift[i].first] == 2)
		{
			--NumTwoCount;
		}

		if (ReceiveGiftCount[GiveGift[i].second] == 2)
		{
			--NumTwoCount;
		}

		++ReceiveGiftCount[GiveGift[i].first];
		++ReceiveGiftCount[GiveGift[i].second];
		ReceiveGiftMember[GiveGift[i].first].insert(i);
		ReceiveGiftMember[GiveGift[i].second].insert(i);
	}

	std::priority_queue<std::pair<int*, int>, std::vector<std::pair<int*, int>>, Comp> pq; //받은 선물 양, 인덱스
	for (int i = 0; i < N; i++)
	{
		pq.push(std::make_pair(&ReceiveGiftCount[i], i));
	}

	while (!IsFair(static_cast<int>(pq.size())))
	{
		std::pair<int*, int> deleteMember = pq.top();
		pq.pop();

		int PopGift1 = GiveGift[deleteMember.second].first;
		int PopGift2 = GiveGift[deleteMember.second].second;

		if (ReceiveGiftCount[PopGift1] == 3)
		{
			++NumTwoCount;
		}

		if (ReceiveGiftCount[PopGift2] == 3)
		{
			++NumTwoCount;
		}

		if (ReceiveGiftCount[PopGift1] == 2)
		{
			--NumTwoCount;
		}

		if (ReceiveGiftCount[PopGift2] == 2)
		{
			--NumTwoCount;
		}

		--ReceiveGiftCount[PopGift1];
		--ReceiveGiftCount[PopGift2];
		//auto EraseIter1 = ReceiveGiftMember[PopGift1].find(deleteMember.second);
		//auto EraseIter2 = ReceiveGiftMember[PopGift1].find(deleteMember.second);
	}
	
	int Size = pq.size();
	std::cout << Size << "\n";

	for (size_t i = 0; i < Size; i++)
	{
		int PrintMember = pq.top().second + 1;
		pq.pop();

		std::cout << PrintMember << " ";
	}

	return 0;
}
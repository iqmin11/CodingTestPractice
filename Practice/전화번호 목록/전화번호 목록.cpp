//https://www.acmicpc.net/problem/5052

#include <iostream>
#include <vector>
#include <string_view>

class Trie
{
public:
	class TrieNode
	{
	public:

		TrieNode()
			: bLeafNode(false)
		{
			LinkNodes.resize(10, nullptr);
		}

		~TrieNode()
		{
			for (size_t i = 0; i < 10; i++)
			{
				if (LinkNodes[i] != nullptr)
				{
					delete LinkNodes[i];
				}
			}
		}

		void Insert(const std::string_view::iterator CurIter, const std::string_view::iterator EndIter)
		{
			if (CurIter == EndIter)
			{
				bool PrevState = bLeafNode;
				IsLeafNode();
				if (bLeafNode == true)
				{
					if (PrevState != bLeafNode)
					{
						++LeafNodeCount;
					}
				}
			}
			else
			{
				int CurIndex = *CurIter - '0';
				if (LinkNodes[CurIndex] == nullptr)
				{
					LinkNodes[CurIndex] = new TrieNode();
				}

				if (bLeafNode)
				{
					bLeafNode = false;
					--LeafNodeCount;
				}
				LinkNodes[CurIndex]->Insert(CurIter + 1, EndIter);
			}
		}

		bool IsLeafNode()
		{
			for (auto i : LinkNodes)
			{
				if (i != nullptr)
				{
					bLeafNode = false;
					return bLeafNode;
				}
			}
			bLeafNode = true;
			return bLeafNode;
		}

		bool bLeafNode = false;
		std::vector<TrieNode*> LinkNodes;
		static int LeafNodeCount;
	};

public:
	Trie()
	{
		RootNode = new TrieNode();
	}

	~Trie()
	{
		delete RootNode;
	}

	void Insert(std::string_view InsertStr)
	{
		if (InsertStr.empty())
		{
			return;
		}

		RootNode->Insert(InsertStr.begin(), InsertStr.end());
	}

	TrieNode* RootNode = nullptr;
};

int Trie::TrieNode::LeafNodeCount = 0;
int t, n;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> t;
	std::vector<std::string> Answers;
	Answers.reserve(t);
	for (size_t k = 0; k < t; k++)
	{
		Trie TrieContainer;
		Trie::TrieNode::LeafNodeCount = 0;

		std::cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			std::string Input;
			std::cin >> Input;
			TrieContainer.Insert(Input);
		}

		if (Trie::TrieNode::LeafNodeCount == n)
		{
			Answers.push_back("YES");
		}
		else
		{
			Answers.push_back("NO");
		}
	}

	for (size_t i = 0; i < t; i++)
	{
		std::cout << Answers[i] << "\n";
	}
}


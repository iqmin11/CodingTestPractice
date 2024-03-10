#include <iostream>
#include <vector>
#include <string_view>

void PrintBool(bool _result)
{
	if (_result)
	{
		std::cout << "True" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}
}

class Trie
{
private:
	class TrieNode
	{
	public:
		TrieNode()
			: IsFinish(false)
		{
			LinkNode.resize(26, nullptr);
		}

		~TrieNode()
		{
			for (size_t i = 0; i < 26; i++)
			{
				if (LinkNode[i] != nullptr)
				{
					delete LinkNode[i];
				}
			}
		}

		void Insert(const std::string_view::iterator CurKey, const std::string_view::iterator EndKey)
		{
			if (CurKey == EndKey)
			{
				IsFinish = true;
			}
			else
			{
				int CurIndex = *CurKey - 'A';
				if (LinkNode[CurIndex] == nullptr)
				{
					LinkNode[CurIndex] = new TrieNode();
				}
				LinkNode[CurIndex]->Insert(CurKey + 1, EndKey);
			}
		}

		bool Find(const std::string_view::iterator CurKey, const std::string_view::iterator EndKey)
		{
			if (CurKey == EndKey)
			{
				if (IsFinish)
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			int CurIndex = *CurKey - 'A';
			if (LinkNode[CurIndex] == nullptr)
			{
				return false;
			}

			return LinkNode[CurIndex]->Find(CurKey + 1, EndKey);
		}

		bool IsFinish;
		std::vector<TrieNode*> LinkNode;
	};

public:
	Trie()
	{
		RootNode = new TrieNode;
	}

	~Trie()
	{
		delete RootNode;
	}

	void Insert(std::string_view _Str)
	{
		if (_Str.empty())
		{
			return;
		}

		RootNode->Insert(_Str.begin(), _Str.end());
	}

	bool Find(std::string_view _Str)
	{
		if (_Str.empty())
		{
			return false;
		}

		return RootNode->Find(_Str.begin(), _Str.end());
	}

	TrieNode* RootNode = nullptr;
};


int main()
{
	{
		Trie Test;
		Test.Insert("TEST");
		Test.Insert("TEAA");
		
		bool Result = false;
		Result = Test.Find("TES");
		PrintBool(Result);
		Result = Test.Find("TEST");
		PrintBool(Result);
		Result = Test.Find("TEAA");
		PrintBool(Result);
		Result = Test.Find("AA");
		PrintBool(Result);
	}
	_CrtDumpMemoryLeaks();
}
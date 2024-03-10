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
			if (CurKey == EndKey) //글자를 다넣었다면
			{
				IsFinish = true; //현재 노드가 마지막 노드
			}
			else
			{
				int CurIndex = *CurKey - 'A'; //인덱스
				if (LinkNode[CurIndex] == nullptr) //널이면
				{
					LinkNode[CurIndex] = new TrieNode(); // 노드 동적할당 
				}
				LinkNode[CurIndex]->Insert(CurKey + 1, EndKey); //재귀
			}
		}

		bool Find(const std::string_view::iterator CurKey, const std::string_view::iterator EndKey)
		{
			if (CurKey == EndKey) //글자 다 찾아봄
			{
				if (IsFinish) //얘가 마지막글자여?
				{
					return true; //맞어
				}
				else
				{
					return false; //아녀
				}
			}

			int CurIndex = *CurKey - 'A'; // 현재 글자의 인덱스 
			if (LinkNode[CurIndex] == nullptr) //null이면 삽입 안되어있다는거자너
			{
				return false;
			}

			return LinkNode[CurIndex]->Find(CurKey + 1, EndKey); //다 잘 했으면 재귀
		}

		bool IsFinish; //마지막 노드인지 아닌지 체크
		std::vector<TrieNode*> LinkNode; //26개의 노드(알파벳, 이친구의 데이터는 인덱스로 기록한다고 생각하셈)
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

	void Insert(std::string_view _Str) //글자를 삽입
	{
		if (_Str.empty())
		{
			return;
		}

		RootNode->Insert(_Str.begin(), _Str.end()); //첫 글자부터 돌면서 재귀식으로 삽입
	}

	bool Find(std::string_view _Str)
	{
		if (_Str.empty())
		{
			return false;
		}

		return RootNode->Find(_Str.begin(), _Str.end()); //첫 글자부터 돌면서 재귀식으로 검색
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
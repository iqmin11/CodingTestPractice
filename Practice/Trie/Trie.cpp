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
			if (CurKey == EndKey) //���ڸ� �ٳ־��ٸ�
			{
				IsFinish = true; //���� ��尡 ������ ���
			}
			else
			{
				int CurIndex = *CurKey - 'A'; //�ε���
				if (LinkNode[CurIndex] == nullptr) //���̸�
				{
					LinkNode[CurIndex] = new TrieNode(); // ��� �����Ҵ� 
				}
				LinkNode[CurIndex]->Insert(CurKey + 1, EndKey); //���
			}
		}

		bool Find(const std::string_view::iterator CurKey, const std::string_view::iterator EndKey)
		{
			if (CurKey == EndKey) //���� �� ã�ƺ�
			{
				if (IsFinish) //�갡 ���������ڿ�?
				{
					return true; //�¾�
				}
				else
				{
					return false; //�Ƴ�
				}
			}

			int CurIndex = *CurKey - 'A'; // ���� ������ �ε��� 
			if (LinkNode[CurIndex] == nullptr) //null�̸� ���� �ȵǾ��ִٴ°��ڳ�
			{
				return false;
			}

			return LinkNode[CurIndex]->Find(CurKey + 1, EndKey); //�� �� ������ ���
		}

		bool IsFinish; //������ ������� �ƴ��� üũ
		std::vector<TrieNode*> LinkNode; //26���� ���(���ĺ�, ��ģ���� �����ʹ� �ε����� ����Ѵٰ� �����ϼ�)
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

	void Insert(std::string_view _Str) //���ڸ� ����
	{
		if (_Str.empty())
		{
			return;
		}

		RootNode->Insert(_Str.begin(), _Str.end()); //ù ���ں��� ���鼭 ��ͽ����� ����
	}

	bool Find(std::string_view _Str)
	{
		if (_Str.empty())
		{
			return false;
		}

		return RootNode->Find(_Str.begin(), _Str.end()); //ù ���ں��� ���鼭 ��ͽ����� �˻�
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
#include <iostream>
#include <map>
#include <functional>
#include <crtdbg.h>

typedef int T1;
typedef int T2;

//template <typename T1, typename T2>
class MyMap
{
private:
	class Tree_Node
	{
	public:
		Tree_Node* find(const T1& _SearchKey)
		{
			if (Value == nullptr)// �˻� ��尡 ��� ����� ���
			{
				Tree_Node* Myhead = this;
				if (Parent == Myhead) //�˻��Ұ� ���� �����Ծ��
				{
					return this;
				}

				return Parent->find(_SearchKey);
			}

			if (Value->first == _SearchKey)
			{
				return this;
			}

			if (Value->first > _SearchKey)
			{
				if (Left->Value != nullptr)
				{
					return Left->find(_SearchKey);
				}
				return Left;
			}

			if (Value->first < _SearchKey)
			{
				if (Right->Value != nullptr)
				{
					return Right->find(_SearchKey);
				}
				return Right;
			}
		}

		std::pair<Tree_Node*, bool> insert(const std::pair<T1, T2>& _Value)
		{
			if (Value == nullptr) // �˻� ��尡 ��� ����� ���
			{
				Tree_Node* Myhead = this;

				if (Parent == Myhead) // ���� �μ�Ʈ
				{
					Tree_Node* insertNode = new Tree_Node;
					insertNode->Value = new std::pair<T1, T2>;
					*insertNode->Value = _Value;

					insertNode->Left = Myhead;
					insertNode->Parent = Myhead;
					insertNode->Right = Myhead;

					Left = insertNode;
					Parent = insertNode;
					Right = insertNode;
					return std::make_pair(insertNode, true);
				}

				return Parent->insert(_Value);
			}

			if (_Value.first == Value->first) //key ���� ���ٸ�
			{
				return std::make_pair(this, false);
			}

			if (_Value.first < Value->first) //key ���� �۴ٸ�
			{
				if (Left->Value == nullptr) //left�� end���
				{
					Tree_Node* Myhead = Left;

					Tree_Node* insertNode = new Tree_Node;
					insertNode->Value = new std::pair<T1, T2>;
					*insertNode->Value = _Value;
					insertNode->Parent = this;
					insertNode->Left = Myhead;
					insertNode->Right = Myhead;
					Left = insertNode;

					if (Myhead->Left->Value->first > insertNode->Value->first)
					{
						Myhead->Left = insertNode;
					}

					return std::make_pair(insertNode, true);
				}
				else
				{
					return Left->insert(_Value);
				}
			}

			if (_Value.first > Value->first) //key ���� ũ�ٸ�
			{
				if (Right->Value == nullptr) //right�� end���
				{
					Tree_Node* Myhead = Right;

					Tree_Node* insertNode = new Tree_Node;
					insertNode->Value = new std::pair<T1, T2>;
					*insertNode->Value = _Value;
					insertNode->Parent = this;
					insertNode->Left = Myhead;
					insertNode->Right = Myhead;
					Right = insertNode;

					if (Myhead->Right->Value->first < insertNode->Value->first)
					{
						Myhead->Right = insertNode;
					}

					return std::make_pair(insertNode, true);
				}
				else
				{
					return Right->insert(_Value);
				}
			}
		}

		void preorder(std::function<void()> _Event)
		{
			_Event();
			if (Left->Value != nullptr)
			{
				Left->preorder(_Event);
			}
			if (Right->Value != nullptr)
			{
				Right->preorder(_Event);
			}
		}

		void inorder(std::function<void()> _Event)
		{
			if (Left->Value != nullptr)
			{
				Left->inorder(_Event);
			}
			_Event();
			if (Right->Value != nullptr)
			{
				Right->inorder(_Event);
			}
		}

		void postorder(std::function<void()> _Event)
		{
			if (Left->Value != nullptr)
			{
				Left->postorder(_Event);
			}
			if (Right->Value != nullptr)
			{
				Right->postorder(_Event);
			}
			_Event();
		}

		std::pair<T1, T2>* Value = nullptr;
		Tree_Node* Left = nullptr;
		Tree_Node* Parent = nullptr;
		Tree_Node* Right = nullptr;
	};

public:
	class iterator
	{
		friend MyMap;
	public:

	private:
		iterator(Tree_Node* _ptr)
			: Iter(_ptr)
		{

		}
		Tree_Node* Iter = nullptr;
	};

	MyMap()
		: Myhead()
	{
		Myhead.Left = &Myhead;
		Myhead.Parent = &Myhead;
		Myhead.Right = &Myhead;
	}

	~MyMap()
	{
		Myhead.Parent->postorder([]()
			{
			});
	}

	iterator find(const T1& _Value)
	{
		return iterator(Myhead.Parent->find(_Value));
	}

	std::pair<iterator, bool> insert(const std::pair<T1, T2>& _Value)
	{
		std::pair<Tree_Node*, bool> result = Myhead.Parent->insert(_Value);
		if (result.second)
		{
			_size++;
		}
		return std::make_pair(iterator(result.first), result.second);
	}

	iterator begin()
	{
		return iterator(Myhead.Left);
	}

	iterator end()
	{
		return iterator(&Myhead);
	}

private:
	Tree_Node Myhead = Tree_Node();
	size_t _size = 0;
};

int main()
{
	std::map<int, int> Ex;

	Ex.insert(std::make_pair(1, 1));
	Ex.insert(std::make_pair(2, 1));
	Ex.insert(std::make_pair(3, 1));
	Ex.insert(std::make_pair(4, 1));
	Ex.insert(std::make_pair(5, 1));
	std::pair<std::map<int, int>::iterator, bool> Test1 = Ex.insert(std::make_pair(6, 1));
	std::pair<std::map<int, int>::iterator, bool> Test2 = Ex.insert(std::make_pair(6, 10));

	std::map<int, int>::iterator Enditer = Ex.end();
	//Ex.find(2);

	for (std::map<int, int>::iterator Curiter = Ex.begin(); Curiter != Enditer; Curiter++)
	{
		std::cout << Curiter->first << " ";
	}

	MyMap My;
	My.insert(std::make_pair(2, 1));
	My.insert(std::make_pair(1, 1));
	My.insert(std::make_pair(4, 1));
	My.insert(std::make_pair(3, 1));
	My.insert(std::make_pair(5, 1));
	My.insert(std::make_pair(6, 1));
	My.insert(std::make_pair(6, 10));

	MyMap::iterator SIter = My.begin();
	MyMap::iterator EIter = My.end();

	MyMap::iterator FindIter = My.find(0);

	/*for (size_t i = 0; i < length; i++)
	{

	}*/
	int a = 0;
}
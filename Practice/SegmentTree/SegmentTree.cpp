#include <iostream>
#include <vector>
#include <set>

class SegmentTree
{
	class SegmentTreeNode
	{

	public:
		SegmentTreeNode(size_t _Left, size_t _Right, const std::vector<int>& _Data)
		{
			LeftIndex = _Left;
			RightIndex = _Right;
			if (_Left == _Right)
			{
				Data = _Data[_Right];
				return;
			}

			size_t Mid = (_Left + _Right) / 2;
			LeftNode = new SegmentTreeNode(_Left, Mid, _Data);
			RightNode = new SegmentTreeNode(Mid + 1, _Right, _Data);
			Data = LeftNode->Data + RightNode->Data;
		}

		~SegmentTreeNode()
		{
			if (LeftNode != nullptr)
			{
				delete LeftNode;
			}

			if (RightNode != nullptr)
			{
				delete RightNode;
			}
		}

		size_t LeftIndex = -1;
		size_t RightIndex = -1;
		size_t Data = -1;
		SegmentTreeNode* LeftNode = nullptr;
		SegmentTreeNode* RightNode = nullptr;
	};

public:
	SegmentTree(const std::vector<int>& _Data)
	{
		RootNode = new SegmentTreeNode(0, _Data.size() - 1, _Data);
	}

	~SegmentTree()
	{
		delete RootNode;
	}

private:

	SegmentTreeNode* RootNode = nullptr;
};

int main()
{
	{
		std::vector<int> Vec = { 1,2,3,4,5,6,7,8,9,10 };
		SegmentTree Test = SegmentTree(Vec);
	}
	_CrtDumpMemoryLeaks();
	return 0;
}
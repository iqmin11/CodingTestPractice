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

		size_t FindRangeData(size_t _Start, size_t _End)
		{
			if (_End < LeftIndex || _Start > RightIndex)
			{
				return 0;
			}

			if (_Start == LeftIndex && _End == RightIndex)
			{
				return Data;
			}

			size_t Mid = (LeftIndex + RightIndex) / 2;

			if (Mid < _Start)
			{
				Mid = _Start;
				return LeftNode->FindRangeData(_Start, Mid) + RightNode->FindRangeData(Mid, _End);
			}
			else if (Mid > _End)
			{
				Mid = _End;
				return LeftNode->FindRangeData(_Start, Mid) + RightNode->FindRangeData(Mid, _End);
			}

			return LeftNode->FindRangeData(_Start, Mid) + RightNode->FindRangeData(Mid + 1, _End);
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

	size_t FindRangeData(size_t _Start, size_t _End)
	{
		return RootNode->FindRangeData(_Start, _End);
	}


private:

	SegmentTreeNode* RootNode = nullptr;
};

int main()
{
	{
		std::vector<int> Vec = { 12,3,6,2,7,8,33,1 };
		SegmentTree Test = SegmentTree(Vec);
		size_t a = Test.FindRangeData(0, 2);
		int b = 0;
	}
	_CrtDumpMemoryLeaks();
	return 0;
}
#include <iostream>
#include <memory> //����Ʈ �����͸� ����ϱ� ���� ���
#include <crtdbg.h>

class Node_CirRef
{
public:
	Node_CirRef()
	{
		std::cout << "Node_CirRef Constructor" << std::endl;
	}

	~Node_CirRef()
	{
		std::cout << "Node_CirRef Destructor" << std::endl;
	}

	std::shared_ptr<Node_CirRef> next = nullptr;
};

class Node : public std::enable_shared_from_this<Node> 
{
public:
	Node()
	{
		std::cout << "Node Constructor" << std::endl;
	}

	virtual ~Node()
	{
		std::cout << "Node Destructor" << std::endl;
	}

	std::weak_ptr<Node> next;
};

class DerievedNode : public Node
{
public:
	DerievedNode()
	{
		std::cout << "DerievedNode Constructor" << std::endl;
	}

	~DerievedNode() override
	{
		std::cout << "DerievedNode Destructor" << std::endl;
	}

	std::shared_ptr<DerievedNode> ReturnThis()
	{
		//return this; �Ϲ����� ������δ� �Ұ�����
		return std::dynamic_pointer_cast<DerievedNode>(this->shared_from_this());
	}

	DerievedNode* ReturnRawThis()
	{
		return this;
	}

};

int main()
{
	new int; // �ŷ��� ��
	//unique_ptr : �Ѱ��� ���ʽ��� ���, ������ �Ұ���, �̵��� ����
	{
		std::unique_ptr<int> Uptr(new int); //��ȿ���� ����� �ʱ�ȭ, make_unique�Լ��� Ȱ���ϴ� ���� ����
		*Uptr = 10;
		std::unique_ptr<int> Share = nullptr;
		//Share = Uptr; // ���� �� ���� �Ұ���

		std::unique_ptr<int> Move = nullptr;
		Move = std::move(Uptr); // �̵��� ����
		Uptr.reset(new int); //���ο� �޸𸮿� ���� ���ʽ� ����
		Uptr = std::make_unique<int>(42); //�Ѱ��� ��� ��. �̶� ���� reset���� ������ �޸𸮴� �����ϰ��ִ� ���ʽ��� ������鼭 �ڵ����� delete��.
	
		//�ٸ� �ڷ������� ĳ���� ������ �ȵ�
	}
	
	//shared_ptr : �������� ���ʽ��� ����ϱ� ���ؼ� ������� ����Ʈ ������, ���� Ƚ��(Ref count)�� ����ϴ� ���
	{
		std::shared_ptr<int> Sptr = std::make_shared<int>(20); //����, Ref count 1
		std::shared_ptr<int> Share = nullptr;
		Share = Sptr; //���� ����, Ref count 2

		std::shared_ptr<int> Move = nullptr;
		Move = std::move(Sptr); // �̵�, Ref count 2
		Move.reset(new int(10)); // ����, 10->Ref count1 / 20->Ref count1

		const std::shared_ptr<int>& ConstRef = Move; //�������·� pass�ҽ�, ���۷���ī���Ͱ� ���� ����. 10->Ref count1
		std::shared_ptr<int>& Ref = Move; //10->Ref count1
		
		//Ref Count�� 0�� �Ǹ� �޸� �����ϴ� ������ ����

		//���� casting�� ����
		std::shared_ptr<Node> node = std::make_shared<DerievedNode>();
		std::shared_ptr<DerievedNode> StaticCast = nullptr;
		std::shared_ptr<DerievedNode> DownCast = nullptr;
		StaticCast = std::static_pointer_cast<DerievedNode>(node);
		DownCast = std::dynamic_pointer_cast<DerievedNode>(node);
		//std::const_pointer_cast<>();

		//���ǻ��� : ��ȯ ����
		{
			std::shared_ptr<Node_CirRef> node1 = std::make_shared<Node_CirRef>(); //node1 Ref Count = 1
			std::shared_ptr<Node_CirRef> node2 = std::make_shared<Node_CirRef>(); //node2 Ref Count = 1

			node1->next = node2; //node1 Ref Count = 1, node2 Ref Count = 2
			node2->next = node1; //node1 Ref Count = 2, node2 Ref Count = 2
		}

		// �������� node1 �ı� Ref Count = 1, �������� node2 �ı� Ref Count = 1
		// Ref Count�� 0�� �ƴϱ� ������ ����� �Ҹ��ڴ� ȣ����� ����, memory leak
	}

	//weak_ptr : ��������(������ ���� ������ �����ϳ� Ref Count�� �ø��°��� �ƴѰ�츦 ���������� ������), ��ȯ���� ���� ����
	{
		{
			std::shared_ptr<Node> node1 = std::make_shared<Node>(); //node1 Ref Count = 1
			std::shared_ptr<Node> node2 = std::make_shared<Node>(); //node2 Ref Count = 1

			node1->next = node2; //node1 Ref Count = 1, node2 Ref Count = 1
			node2->next = node1; //node1 Ref Count = 1, node2 Ref Count = 1

			bool Check = node1->next.expired(); //���ʽ��� �����ִ� shared_ptr�� �����ֱ⸦ ���´ٰ� �ص� weak_ptr�� �ı��Ǵ� ���� �ƴ�.
												//����� ��ü�� lock�ҽ� ����ִ� shared_ptr�� ��ȯ��
			int Count = node1.use_count(); //�����ϰ��ִ� shared_ptr�� ref_count�� ��ȯ
		}
		//��ȯ���� ���� �ذ�
	}

	//enable_shared_from_this : �ش� Ŭ�����κ��� �Ļ��� Ŭ�������� raw_ptr�� shared_ptr, weak_ptr�� ��ȯ�� �� �ִ� �Լ��� ����� �� �ִ�
	{
		//make_shared�� �������� �����ż� �� shared_ptr�� ������ ���̾�
		//�ش� Ŭ������ ������� �ν��Ͻ��� this�� shared_ptr���·� ��ȯ�� �� �ְ� ���ִ� Ŭ����
		std::shared_ptr<DerievedNode> nodeSptr = std::make_shared<DerievedNode>();
		std::shared_ptr<DerievedNode> returnThisSptr = nodeSptr->ReturnThis();

		DerievedNode* BadObjPtr = new DerievedNode; //shared_ptr�� �����Ǵ� ���� �ƴϸ� ����ġ ���� ������ �߻��� �� ����.
		std::shared_ptr<DerievedNode> BadSharedPtr = BadObjPtr->ReturnThis(); //Refī��Ʈ�� �÷���
		delete BadObjPtr; //�𸮸� ���̰�, ���� �ı�, �ٵ� Refī��Ʈ�� 0�� �����ϱ� ����� ptr�� ��۸������͸� �ѹ� �� �������Ϸ�����->��Ÿ�� ���� �߻�.
		//enable_shared_from_this�� ���� �Ļ��� Ŭ������ �ݵ�� �ݵ�� shared_ptr�� ������ ��
	}

	_CrtDumpMemoryLeaks();
}
#include <iostream>
#include <memory> //스마트 포인터를 사용하기 위한 헤더
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
		//return this; 일반적인 방법으로는 불가능함
		return std::dynamic_pointer_cast<DerievedNode>(this->shared_from_this());
	}

	DerievedNode* ReturnRawThis()
	{
		return this;
	}

};

int main()
{
	new int; // 신뢰의 릭
	//unique_ptr : 한개의 오너쉽만 허용, 공유가 불가능, 이동은 가능
	{
		std::unique_ptr<int> Uptr(new int); //비효율적 방식의 초기화, make_unique함수를 활용하는 것을 권장
		*Uptr = 10;
		std::unique_ptr<int> Share = nullptr;
		//Share = Uptr; // 복사 및 공유 불가능

		std::unique_ptr<int> Move = nullptr;
		Move = std::move(Uptr); // 이동은 가능
		Uptr.reset(new int); //새로운 메모리에 대한 오너십 세팅
		Uptr = std::make_unique<int>(42); //한가지 방법 더. 이때 위에 reset으로 세팅한 메모리는 소유하고있는 오너쉽이 사라지면서 자동으로 delete됨.
	
		//다른 자료형으로 캐스팅 지원이 안됨
	}
	
	//shared_ptr : 여러개의 오너쉽을 허용하기 위해서 만들어진 스마트 포인터, 참조 횟수(Ref count)를 계산하는 방식
	{
		std::shared_ptr<int> Sptr = std::make_shared<int>(20); //생성, Ref count 1
		std::shared_ptr<int> Share = nullptr;
		Share = Sptr; //복사 가능, Ref count 2

		std::shared_ptr<int> Move = nullptr;
		Move = std::move(Sptr); // 이동, Ref count 2
		Move.reset(new int(10)); // 리셋, 10->Ref count1 / 20->Ref count1

		const std::shared_ptr<int>& ConstRef = Move; //참조형태로 pass할시, 레퍼런스카운터가 늘지 않음. 10->Ref count1
		std::shared_ptr<int>& Ref = Move; //10->Ref count1
		
		//Ref Count가 0이 되면 메모리 삭제하는 식으로 관리

		//여러 casting을 지원
		std::shared_ptr<Node> node = std::make_shared<DerievedNode>();
		std::shared_ptr<DerievedNode> StaticCast = nullptr;
		std::shared_ptr<DerievedNode> DownCast = nullptr;
		StaticCast = std::static_pointer_cast<DerievedNode>(node);
		DownCast = std::dynamic_pointer_cast<DerievedNode>(node);
		//std::const_pointer_cast<>();

		//주의사항 : 순환 참조
		{
			std::shared_ptr<Node_CirRef> node1 = std::make_shared<Node_CirRef>(); //node1 Ref Count = 1
			std::shared_ptr<Node_CirRef> node2 = std::make_shared<Node_CirRef>(); //node2 Ref Count = 1

			node1->next = node2; //node1 Ref Count = 1, node2 Ref Count = 2
			node2->next = node1; //node1 Ref Count = 2, node2 Ref Count = 2
		}

		// 지역변수 node1 파괴 Ref Count = 1, 지역변수 node2 파괴 Ref Count = 1
		// Ref Count가 0이 아니기 때문에 노드의 소멸자는 호출되지 않음, memory leak
	}

	//weak_ptr : 약한참조(참조를 통한 접근은 가능하나 Ref Count를 늘리는것은 아닌경우를 약한참조로 정의함), 순환참조 문제 방지
	{
		{
			std::shared_ptr<Node> node1 = std::make_shared<Node>(); //node1 Ref Count = 1
			std::shared_ptr<Node> node2 = std::make_shared<Node>(); //node2 Ref Count = 1

			node1->next = node2; //node1 Ref Count = 1, node2 Ref Count = 1
			node2->next = node1; //node1 Ref Count = 1, node2 Ref Count = 1

			bool Check = node1->next.expired(); //오너쉽을 갖고있는 shared_ptr가 생애주기를 끝냈다고 해도 weak_ptr이 파괴되는 것은 아님.
												//만료된 개체를 lock할시 비어있는 shared_ptr을 반환함
			int Count = node1.use_count(); //참조하고있는 shared_ptr의 ref_count를 반환
		}
		//순환참조 문제 해결
	}

	//enable_shared_from_this : 해당 클래스로부터 파생된 클래스들은 raw_ptr을 shared_ptr, weak_ptr로 변환할 수 있는 함수를 사용할 수 있다
	{
		//make_shared로 힙영역에 구현돼서 난 shared_ptr로 관리될 놈이야
		//해당 클래스로 만들어진 인스턴스의 this를 shared_ptr형태로 변환할 수 있게 해주는 클래스
		std::shared_ptr<DerievedNode> nodeSptr = std::make_shared<DerievedNode>();
		std::shared_ptr<DerievedNode> returnThisSptr = nodeSptr->ReturnThis();

		DerievedNode* BadObjPtr = new DerievedNode; //shared_ptr로 관리되는 놈이 아니면 예기치 않은 오류가 발생할 수 있음.
		std::shared_ptr<DerievedNode> BadSharedPtr = BadObjPtr->ReturnThis(); //Ref카운트를 늘렸음
		delete BadObjPtr; //모리를 죽이고, 오너 파괴, 근데 Ref카운트가 0이 됐으니까 쉐어드 ptr이 댕글링포인터를 한번 더 릴리즈하려고함->런타임 오류 발생.
		//enable_shared_from_this로 부터 파생된 클래스는 반드시 반드시 shared_ptr로 관리할 것
	}

	_CrtDumpMemoryLeaks();
}
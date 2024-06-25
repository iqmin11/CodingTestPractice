#include <iostream>
#include <map>
#include <memory>

//Observer가 Subject의 상태 변화를 감지
//그에 따른 Observer 무언가 하면 됨

class ObserverInterface
{
public:
	virtual ~ObserverInterface() 
	{
		std::cout << "Delete : " << ObserverName << std::endl;
	}

	virtual void Update(int State) = 0;

	void SetSubObj(class Subject* SubPtr)
	{
		SubObj = SubPtr;
	}
	
	std::string GetName() const
	{
		return ObserverName;
	}

	void SetName(const std::string& Name)
	{
		ObserverName = Name;
	}

private:
	std::string ObserverName;
	Subject* SubObj = nullptr;
};

class Observer : public ObserverInterface
{
public:
	void Update(int State) override
	{
		std::cout << GetName() << ": " << "Subject Change State To " << State << std::endl;
		DoSomthing(State);
	}

private:
	void DoSomthing(int State)
	{
		std::cout << GetName() << " : " << "DoSomthing" << std::endl;
	}
};

class Subject
{
public:
	~Subject()
	{
		Observers.clear();
	}

	void Attach(std::shared_ptr<Observer> ObPtr)
	{
		if (ObPtr->GetName() == "")
		{
			std::cout << "Please Set Name" << std::endl;
			return;
		}

		Observers.insert(std::make_pair(ObPtr->GetName(), ObPtr));
		ObPtr->SetSubObj(this);
	}

	void Detach(const std::string& ObName)
	{
		auto FindIter = Observers.find(ObName);

		if (FindIter == Observers.end())
		{
			return;
		}

		FindIter->second->SetSubObj(nullptr);
		Observers.erase(FindIter);
	}

	void SetState(int StateValue)
	{
		State = StateValue;
		Notify();
	}

	int GetState() const
	{
		return State;
	}

private:
	void Notify() // Brodcast
	{
		for (auto Observer : Observers)
		{
			Observer.second->Update(State);
		}
	}

	int State = 0;
	std::map<std::string, std::shared_ptr<Observer>> Observers;
};

int main()
{
	std::shared_ptr<Observer> Ob1 = std::make_shared<Observer>();
	Ob1->SetName("Test1");
	std::shared_ptr<Observer> Ob2 = std::make_shared<Observer>();
	Ob2->SetName("Test2");
	std::shared_ptr<Observer> Ob3 = std::make_shared<Observer>();
	Ob3->SetName("Test3");

	Subject Sub;
	Sub.Attach(Ob1);
	Sub.Attach(Ob2);
	Sub.Attach(Ob3);

	Sub.SetState(3);

	Sub.Detach("Test2");

	Sub.SetState(2);

	return 0;
}
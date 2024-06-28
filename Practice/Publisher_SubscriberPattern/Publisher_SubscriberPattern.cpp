#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <string>

class EventManager
{
public:
	void Subscribe
	(
		const std::string& EventType,
		const std::function<void(const std::string&)>& SubscriberCallback
	)
	{
		Subscribers[EventType].push_back(SubscriberCallback);
	}

	void Publish(const std::string& EventType, const std::string& Message) const
	{
		auto FindIter = Subscribers.find(EventType);
		if (FindIter != Subscribers.end())
		{
			for (const auto& SubscriberCallback : FindIter->second)
			{
				SubscriberCallback(Message);
			}
		}
	}

private:
	std::unordered_map<std::string, std::vector<std::function<void(const std::string&)>>> Subscribers;
};

class Publisher
{
public:
	Publisher(EventManager& MessageBroker)
		: MyManager(MessageBroker) {}

	void PublishEvent(const std::string& EventType, const std::string& Message)
	{
		MyManager.Publish(EventType, Message);
	}

private:
	EventManager& MyManager;
};

class Subscriber
{
public:
	Subscriber
	(
		EventManager& MessageBroker,
		const std::string& EventType,
		const std::string& SubscriberName
	)
		: SubscriberName(SubscriberName)
	{
		MessageBroker.Subscribe(EventType, [this](const std::string& Message)
			{
				this->HandleEvent(Message);
			});
	}
	
	void HandleEvent(const std::string& Message) const
	{
		std::cout << "Subscriber : " << SubscriberName << " Received : " << Message << std::endl;
	}


private:
	std::string SubscriberName;
};

int main()
{
	EventManager MessageBroker;
	
	Publisher Pub(MessageBroker);

	//이벤트를 구독한 구독자들
	Subscriber Sub1(MessageBroker, "Event1", "Hwang");
	Subscriber Sub2(MessageBroker, "Event2", "Oh");
	Subscriber Sub3(MessageBroker, "Event2", "Suck");
	Subscriber Sub4(MessageBroker, "Event3", "Sik");

	//이벤트를 발행 할 시, 해당 이벤트를 구독한 구독자가 Message를 받아 HandleEvent를 호출
	Pub.PublishEvent("Event1", "Message1");
	Pub.PublishEvent("Event1", "Message2");
	Pub.PublishEvent("Event2", "Message1");
	Pub.PublishEvent("Event2", "Message2");
	Pub.PublishEvent("Event3", "Message3");
	Pub.PublishEvent("Event4", "Message1");


	return 0;
}

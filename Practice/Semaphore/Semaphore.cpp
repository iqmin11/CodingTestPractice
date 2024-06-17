#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>
#include <chrono>

std::counting_semaphore<3> sem(3); // �ʱ� ī��Ʈ 3 (3���� �ڿ�)

void useResource(int id, int resource) 
{
    sem.acquire(); // �������� ȹ��
    std::cout << "Thread " << id << " acquires resource " << resource << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // �Ͻ������� �ڿ� ���
    std::cout << "Thread " << id << " releases resource " << resource << std::endl;
    sem.release(); // �������� ����
}

int main() 
{
    std::vector<std::thread> threads;

    // ���� �����尡 ���� �ڿ��� ����ϵ��� ����
    for (int i = 0; i < 6; ++i) {
        threads.emplace_back(useResource, i + 1, i % 3); // 3���� �ڿ��� ����ϴ� 6���� ������
    }

    // �� �������� ���Ḧ ��ٸ�
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>
#include <chrono>

std::counting_semaphore<3> sem(3); // 초기 카운트 3 (3개의 자원)

void useResource(int id, int resource) 
{
    sem.acquire(); // 세마포어 획득
    std::cout << "Thread " << id << " acquires resource " << resource << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // 일시적으로 자원 사용
    std::cout << "Thread " << id << " releases resource " << resource << std::endl;
    sem.release(); // 세마포어 해제
}

int main() 
{
    std::vector<std::thread> threads;

    // 여러 스레드가 각자 자원을 사용하도록 설정
    for (int i = 0; i < 6; ++i) {
        threads.emplace_back(useResource, i + 1, i % 3); // 3개의 자원을 사용하는 6개의 스레드
    }

    // 각 스레드의 종료를 기다림
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
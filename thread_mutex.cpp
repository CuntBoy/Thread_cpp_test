#include <thread>
#include <iostream>
#include <mutex>
#include "unistd.h"

//  初始化锁
int num = 0;
std::mutex mutex;

void push()
{
    // Lock _ guard 类是一个互斥对象包装器，它提供了一个方便的 rai 风格的机制，用于在作用域块期间拥有互斥对象
    // 当创建一个 lock _ guard 对象时，它尝试获得给定的互斥对象的所有权。当控件离开创建 lock _ guard 对象的作用域时，lock _ guard 被析构并释放互斥锁。
    std::lock_guard<std::mutex> guard(mutex);  // 更加异常安全的方式访问 mutex
    std::cout << num++ << std::endl;
}


int main()
{
    // 创建线程
    std::thread threads[100];
    for(auto & i: threads)
    {
        // 创建线程对象  -- 创建即是开始
        i = std::thread(push);
    }
    for(auto & signal_thread: threads)
    {
        signal_thread.join();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));   // 100 毫秒
    }

    return 0;
}

#include <thread>
#include "unistd.h"
#include <iostream>

void func()
{
    // 获取线程ID
    std::cout<<"input thread id: " << std::this_thread::get_id()<<std::endl;
    std::cout<< "Do some work"<<std::endl;
    // 睡眠 500 毫秒
    // std::this_thread::sleep_for(std::chrono::microseconds(500));
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "output thread id: " << std::this_thread::get_id() << std::endl;
}

int main(int argc,char ** argv)
{
    // 获取主线程ID
    std::cout<<"Main thread ID: "<<std::this_thread::get_id()<<std::endl;

    // create thread 创建 即是启用
    std::thread t(func);

    // 将执行线程与线程对象分开，允许独立执行。一旦线程退出，所有已分配的资源都将被释放。
    t.detach();

    if(!t.joinable())
    {
        //  detach 线程结束后 自动释放相关的资源
        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::cout<<"main thread is waiting thread"<<std::endl;
    }
    else
    {
        t.join();
    }

    return 0;
}
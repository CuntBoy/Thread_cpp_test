#include <iostream>
#include "unistd.h"
#include <thread>
#include <string>

void func_val(int n, std::string s)
{
    for(auto i = 0;i < n;i ++)
    {
        std::cout << "func_val " + s + std::to_string(i) << std::endl;
        //std::this_thread::sleep_for(std::chrono::microseconds(30));
    }
}

void func_ref(int & n, std::string & s)
{
    for (auto i = 0; i < n; i++)
    {
        std::cout << "func_ref " + s + std::to_string(i) << std::endl;
        //std::this_thread::sleep_for(std::chrono::microseconds(30));
    }
    n += n;
}

int main()
{
    int n = 10;
    std::string str = "china";
    std::cout << n << std::endl;

    // 传值 的方式
    std::thread t(func_val, 5, "china");
    // 传引用的方式
    std::thread t_1(func_ref, std::ref(n), std::ref(str));
    t_1.detach();
    t.detach();

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout<<n<<std::endl;

    return 0;
}
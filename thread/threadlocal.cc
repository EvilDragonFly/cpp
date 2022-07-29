//需要包含的头文件
#include <iostream>
#include <thread>
#include <mutex>
std::mutex cout_mutex;    //方便多线程打印

thread_local int x = 1; // 每一个thread都独立含有一份，互不影响，main函数对于x的操作对于其他thread不可见

void thread_func(const std::string& thread_name) {
    for (int i = 0; i < 3; ++i) {
        x++;
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "thread[" << thread_name << "]: x = " << x << std::endl;
    }
    return;
}

int main() {
    x = 2;  //不影响t1和t2
    std::thread t1(thread_func, "t1");
    std::thread t2(thread_func, "t2");
    t1.join();
    t2.join();
    std::cout<<x<<std::endl;
    return 0;
}

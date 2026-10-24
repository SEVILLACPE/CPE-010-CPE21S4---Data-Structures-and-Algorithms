#include <iostream>
#include <thread>

int global_var = 0;

void add(int value) {
    global_var += value;
}

int main() {
    std::cout << "Initial global variable value: " << global_var << std::endl;

    std::thread t1(add, 10);
    std::thread t2(add, 20);
    std::thread t3(add, 30);

    t1.join();
    std::cout << "After T1.join(), global variable value: " << global_var << std::endl;

    t2.join();
    std::cout << "After T2.join(), global variable value: " << global_var << std::endl;

    t3.join();
    std::cout << "After T3.join(), global variable value: " << global_var << std::endl;

    return 0;
}


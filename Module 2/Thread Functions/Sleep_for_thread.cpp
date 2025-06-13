#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;

void thread1(){
    {
        lock_guard<mutex> lock(mtx);
        cout << "Simulation for Sleep_for (Thread 1)" << endl;
    }

    for (int i = 0; i <= 10; i++) {
        {
            lock_guard<mutex> lock(mtx);
            cout << "[Thread 1] TIMER: " << i << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
    }

    {
        lock_guard<mutex> lock(mtx);
        cout << "Timer Done for Thread 1\n" << endl;
    }
}

void thread2(){
    
    {
        lock_guard<mutex> lock(mtx);
        cout << "Simulation for Sleep_for (Thread 2)" << endl;
    }

    for (int i = 0; i <= 10; i++) {
        {
            lock_guard<mutex> lock(mtx);
            cout << "[Thread 2] TIMER: " << i << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
    }

    {
        lock_guard<mutex> lock(mtx);
        cout << "Timer Done for Thread 2\n" << endl;
    }
}

int main(){
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}

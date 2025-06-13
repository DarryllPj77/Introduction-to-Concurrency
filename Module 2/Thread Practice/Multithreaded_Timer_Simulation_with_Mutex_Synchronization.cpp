#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;
//Multithreaded Timer Simulation with Mutex Synchronization

// Shared mutex to ensure thread-safe access to cout
mutex mtx;

// Thread function 1 simulating a countdown timer using sleep_for
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
        // Sleep for 1 second between timer ticks
        this_thread::sleep_for(chrono::seconds(1));
    }

    {
        lock_guard<mutex> lock(mtx);
        cout << "Timer Done for Thread 1\n" << endl;
    }
}

// Thread function 2 simulating a countdown timer using sleep_for
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
        // Sleep for 1 second between timer ticks
        this_thread::sleep_for(chrono::seconds(1));
    }

    {
        lock_guard<mutex> lock(mtx);
        cout << "Timer Done for Thread 2\n" << endl;
    }
}

int main(){
    // Launch both thread functions
    thread t1(thread1);
    thread t2(thread2);

    // Wait for both threads to finish before exiting main
    t1.join();
    t2.join();

    return 0;
}

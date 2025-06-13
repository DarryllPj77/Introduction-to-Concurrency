#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

// This program demonstrates using sleep_until to space thread output evenly every second

void Timer1() {
    // Record the current wall clock time
    auto next_time = system_clock::now();

    for (int i = 1; i <= 5; i++) {
        //next_time += seconds(2); // Schedule next wake-up time
        //this_thread::sleep_until(next_time); // Sleep until that time
        //cout << "Timer1: " << i << endl;
        cout << "Timer1 done" << endl;
    }
    next_time += seconds(2); // Add 2 seconds to current time (which was recorded before the loop)
    this_thread::sleep_until(next_time); // Sleep for the remaining time until that 2-second mark
    cout << "Task1 is Done" << endl;
}

void Timer2() {
    auto next_time = system_clock::now();

    for (int i = 1; i <= 5; i++) {
        //next_time += seconds(2);
        //this_thread::sleep_until(next_time);
        //cout << "Timer2: " << i << endl;
        cout << "Timer2 done" << endl;
    }
     next_time += seconds(2);
        this_thread::sleep_until(next_time);
    cout << "Task2 is Done" << endl;
}

int main() {
    cout << "Practice Timer Simulation" << endl;
    // Launch both timers as separate threads
    thread t1(Timer1);
    thread t2(Timer2);
    
    // Main thread waits for both Timer1 and Timer2 to finish
    t1.join(); // Wait for Timer1 to finish
    t2.join(); // Wait for Timer2 to finish

    return 0;
}


/*Notes
auto now = system_clock::now(); - That line captures the current time at the moment the thread reaches it or start time of the thread.
next_time value represents the time when the thread starts running (or more precisely, when that line is executed inside the thread).
*/

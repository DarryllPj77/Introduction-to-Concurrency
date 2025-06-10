#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void function_thread(int walk){
    while(walk-- > 0){
        cout << walk << " walks to make it at school" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "You're already at school" << endl;
    }
    cout << "Thread_function completed going to school" << endl;
}

int main(){
    cout << "Main thread: Going to school" << endl;

    thread t1(function_thread, 5);
    t1.detach();  // Thread runs independently

    // Main thread waits enough time for detached thread to finish
    this_thread::sleep_for(chrono::seconds(7));

    cout << "Main thread: Finished execution" << endl;
    return 0;
}

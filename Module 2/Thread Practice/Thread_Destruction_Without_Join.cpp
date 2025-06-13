#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
//Thread Destruction Without Join: Cause of std::terminate()
//Crash Case: Forgetting to Join Threads in C++
void thread1(){
    cout << "Simulation for Sleep_for" << endl;
    
}

void thread2(){
    cout << "Simulation for Sleep_until" << endl;
}

int main(){
    thread t1(thread1);
    thread t2(thread2);
    
    
    //t2.join();
    //t1.join();
    
    return 0;
}

//Output: terminate called without an active exception


/*happens because you're not calling join() or detach() on the threads t1 and t2 before the main() function ends. 
When a std::thread object is destroyed and is still joinable, the program will call std::terminate() and crash.*/

/*When you create threads (like t1 and t2), they run concurrently with main(). 
But when main() finishes before those threads complete,
your program crashes unless you do one of the following:*/







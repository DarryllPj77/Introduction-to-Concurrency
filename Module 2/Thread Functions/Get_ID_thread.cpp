#include<iostream>
#include<thread>
#include<chrono>
using namespace std;
//This code is to simulate on how to used the function of thread for getting the ID of it

void thread1(){
    cout << "Thread1 ID:" << this_thread::get_id() << endl;
    
}
void thread2(){
    cout << "Thread2 ID:" << this_thread::get_id() << endl;
    
}


int main(){
    thread t1(thread1);
    thread t2(thread2);
    
    t1.join();
    
    t2.join();
   
    
    return 0;
}

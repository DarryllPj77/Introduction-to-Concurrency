#include<iostream>
#include<thread>
#include<chrono> //I just put it here but not needed
using namespace std;


void Hello(string name){
    cout << "Hello Darryll From " << name << " thread " << endl;
}

int main(){
    
    cout << "Hello Darryll From Main Thread" << endl;
    
    thread t1(Hello, "Function"); // thread object_name ( function_name, arguments... );
    t1.join();
    
    
    return 0;
}

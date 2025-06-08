#include <iostream>
#include <thread> // jthread is part of <thread>
using namespace std;

void greet() {
    cout << "Hello from jthread!" << endl;
}

int main() {
    //jthread object_name ( function_to_run, optional_arguments... );
    thread jt1(greet); // starts a thread and automatically joins when done 
    
    cout << "Hello from main!" << endl;
    //jt1.join();
    // No need to call jt.join() — it's automatic with jthread

    return 0;
}

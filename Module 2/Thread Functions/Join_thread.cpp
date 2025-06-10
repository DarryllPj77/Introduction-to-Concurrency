#include<iostream>
#include<thread>
#include<chrono>
using namespace std;
//In this we will show what is a Join function for threads

int num1 = 5, num2 = 10, total, result; //global assigned variable

void multiply(int a, int b){
    cout << "Multiplication Thread at Multiply Function" << endl;
    result = a * b;
    cout << "Thread Multiply Successfuly done with Output of: " << result << endl;
}


int main(){
  
    cout << "Addition Thread at Main Function" << endl;
    total = num1 + num2;
    
    cout << "Thread Main Successfuly done with Output of: " << total << endl;
    
    thread t1(multiply,num1,num2);
    t1.join(); //ensures that the main thread waits for the multiplication thread to complete before exiting the program.
    
    return 0;
}

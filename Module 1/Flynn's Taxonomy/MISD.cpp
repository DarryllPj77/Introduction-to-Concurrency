#include<iostream>
#include<thread>
using namespace std;

int main(){
    cout << "(Multiple Instruction Single Data) Simulation" << endl;
    int data1 = 10; // single data

            //Multiple Instruction
    cout << "Adding Task1:" << data1 + 5 << endl;
    cout << "Subtraction Task2:" << data1 - 5 << endl;
    cout << "Division Task3:" << data1 / 5 << endl;
    cout << "Multiplication Task4:" << data1 * 5 << endl;

    return 0;
}               
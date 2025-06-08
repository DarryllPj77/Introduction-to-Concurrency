#include<iostream>

using namespace std;

int main(){
    cout << "(Multiple Instruction Multiple Data) Simulation" << endl;
    int data[] = {5,10,15,20,25,35}; //Multiple Data

    //Multiple Instruction
    cout << "Adding Task1:" << data[0] + 5 << endl;
    cout << "Subtraction Task2:" << data[1] - 5 << endl;
    cout << "Division Task3:" << data[2] / 5 << endl;
    cout << "Multiplication Task4:" << data[3] * 5 << endl;
    cout << "Getting Modulus Task5:" << data[4] % 5 << endl;

    return 0;
}
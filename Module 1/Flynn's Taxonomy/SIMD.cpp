#include<iostream>

using namespace std;

int main(){
    cout << "(Single Instruction Multiple Data) Simulation" << endl;
    int data[] = {5,10,15,20,25,35}; //Multiple Data
    

    //Single Instruction to multiply each data to 2
    for(int i = 0; i < 5; i++){
        cout << "Processors: " << i+1 <<"x2" << endl;
        data[i] = data[i] - 2;
        cout << data[i] << endl;
    }

    return 0;
}
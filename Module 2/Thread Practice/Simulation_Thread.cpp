#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std;
using namespace std::chrono;



typedef unsigned long long ull;

ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end) {
    for (ull i = start; i <= end; ++i) {
        if ((i & 1) == 0) { // Checks if the number is even using bitwise AND
            EvenSum += i;
        }
    }
}

void findOdd(ull start, ull end) {
    for (ull i = start; i <= end; ++i) {
        if ((i & 1) == 1) { // Checks if the number is odd using bitwise AND
            OddSum += i;
        }
    }
}

int main() {
    ull start = 0, end = 190000000;

    auto startTime = high_resolution_clock::now();

    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);

    t1.join();
    t2.join();

    // findOdd(start, end);   // These lines are commented out in the image
    // findEven(start, end); // These lines are commented out in the image

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "OddSum  : " << OddSum << endl;
    cout << "EvenSum : " << EvenSum << endl;

    cout << "Sec   : " << duration.count() / 1000000.0 << endl;

    return 0;
}

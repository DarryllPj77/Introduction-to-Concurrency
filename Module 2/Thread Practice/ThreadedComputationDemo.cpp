#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;
using namespace std::chrono;

// ===== TASK 1: Factorial =====
void Task_Factorial() {
    unsigned long long result = 1;
    int n = 16;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    cout << "Factorial of " << n << " is: " << result << endl;
}

// ===== TASK 2: Sorting =====
void Task_Sorting() {
    vector<int> arr(1'000'000);
    generate(arr.begin(), arr.end(), rand);
    sort(arr.begin(), arr.end());
    cout << "Sorting Task Completed." << endl;
}

// ===== TASK 3: Prime Check =====
void Task_PrimeCheck() {
    int limit = 100000;
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) count++;
    }
    cout << "Number of primes up to " << limit << " is: " << count << endl;
}

// ===== TASK 4: File Writing =====
void Task_FileWrite() {
    ofstream file("output.txt");
    for (int i = 0; i < 100000; ++i) {
        file << "Line " << i << ": Writing to file.\n";
    }
    file.close();
    cout << "File Writing Task Completed." << endl;
}

// ===== TASK 5: Simulated Delay =====
void Task_SimulatedDelay() {
    for (int i = 1; i <= 5; i++) {
        cout << "Simulating step " << i << "...\n";
        this_thread::sleep_for(seconds(1));
    }
    cout << "Simulated Delay Task Completed." << endl;
}

// ===== Wrapper Function =====
void PerformanceChecker(int taskChoice) {
    auto start = high_resolution_clock::now();

    switch (taskChoice) {
        case 1: Task_Factorial(); break;
        case 2: Task_Sorting(); break;
        case 3: Task_PrimeCheck(); break;
        case 4: Task_FileWrite(); break;
        case 5: Task_SimulatedDelay(); break;
        default: cout << "Invalid Task Choice.\n"; return;
    }

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << fixed << setprecision(6);
    cout << "Execution time: " << elapsed.count() << " seconds\n";
}

int main() {
    int choice;
    char again;

    do {
        cout << "\n===== Performance Task Menu =====\n";
        cout << "1. Factorial\n";
        cout << "2. Sorting\n";
        cout << "3. Prime Checking\n";
        cout << "4. File Writing\n";
        cout << "5. Simulated Delay\n";
        cout << "Select a task (1-5): ";
        cin >> choice;

        thread t1(PerformanceChecker, choice);
        t1.join();

        cout << "Thread completed.\n";

        cout << "\nDo you want to perform another task? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "Exiting program.\n";
    return 0;
}

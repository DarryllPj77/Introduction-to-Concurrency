#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip> // For fixed and setprecision formatting

using namespace std;
using namespace std::chrono;
//Time Performance Analysis For Factorial Task 
// Function that computes factorial and measures its execution time
void PerformanceChecker() {
    // Record the starting time using high_resolution_clock
    auto start = high_resolution_clock::now();

    // Initialize variables for factorial computation
    unsigned long long result = 1; // To store factorial result
    int n = 16; // Factorial target number

    // Loop to compute factorial of n
    for (int i = 1; i <= n; i++) {
        result *= i;
        cout << "Multiplying " << i << " => current result: " << result << endl;
    }

    // Record the ending time after the computation
    auto end = high_resolution_clock::now();

    // Calculate the duration (end - start)
    duration<double> elapsed = end - start;

    // Format the output to show 6 decimal places (no scientific notation)
    cout << fixed << setprecision(6);
    cout << "Factorial of " << n << " is: " << result << endl;
    cout << "Task Finished. Execution time: " << elapsed.count() << " seconds\n";
}

int main() {
    cout << "Starting Performance Test...\n";

    // Launch the factorial computation in a separate thread
    thread t1(PerformanceChecker);

    // Wait for the thread to finish before ending main program
    t1.join();

    cout << "Thread completed.\n";
    return 0;
}


/*Notes
high_resolution_clock::now() measures precise time points.

duration<double> computes elapsed time in seconds.

fixed << setprecision(6) ensures time is printed in decimal (not scientific).

Using a thread shows how performance can be measured for concurrent tasks.
*/




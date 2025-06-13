#include <iostream>   // For input/output operations (cout)
#include <thread>     // For accessing std::thread and hardware_concurrency()

using namespace std;

int main() {
    // Get the number of logical processors (threads) the CPU supports
    unsigned int threads = thread::hardware_concurrency();

    // Display the number of logical processors
    cout << "Logical processors available: " << threads << endl;

    // Return 0 indicates the program ended successfully
    return 0;
}

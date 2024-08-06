#include <iostream>
#include <thread>
#include <chrono>
#include "StopWatch.h"

using namespace std;

int main() {
    // Create an instance of StopWatch
    StopWatch sw;

    // Notify user that the stopwatch is starting
    cout << "Starting the stopwatch...\n";
    sw.begin();  // Start the stopwatch

    // Simulate a delay to represent code execution
    this_thread::sleep_for(chrono::seconds(2));  // Sleep for 2 seconds

    sw.end();  // Stop the stopwatch
    cout << "Stopping the stopwatch...\n";

    // Fetch and display the elapsed time
    cout << "Elapsed time: " << sw.fetchElapsed_time() << " seconds\n";

    sw.reset();  // Reset the stopwatch to zero
    cout << "Stopwatch reset.\n";

    // Notify user that the stopwatch is starting again
    cout << "Starting the stopwatch again...\n";
    sw.begin();  // Start the stopwatch again

    // Simulate another delay to represent code execution
    this_thread::sleep_for(chrono::seconds(3));  // Sleep for 3 seconds

    sw.end();  // Stop the stopwatch
    cout << "Stopping the stopwatch...\n";

    // Fetch and display the elapsed time of the second interval
    cout << "Elapsed time: " << sw.fetchElapsed_time() << " seconds\n";

    return 0;  // Indicate successful program completion
}




#include "StopWatch.h"
#include <ctime>

using namespace std;

// Constructor to initialize the stopwatch
StopWatch::StopWatch() : begin_time(0), end_time(0), running(false) {}

// Start the stopwatch
void StopWatch::begin() {
    if (!running) {  // Check if the stopwatch is not already running
        begin_time = getProcessTime();  // Record the start time
        running = true;  // Set the running flag to true
    }
}

// Stop the stopwatch
void StopWatch::end() {
    if (running) {  // Check if the stopwatch is currently running
        end_time = getProcessTime();  // Record the end time
        running = false;  // Set the running flag to false
    }
}

// Reset the stopwatch to its initial state
void StopWatch::reset() {
    begin_time = 0;  // Set the start time to zero
    end_time = 0;    // Set the end time to zero
    running = false; // Reset the running flag
}

// Fetch the elapsed time in seconds
double StopWatch::fetchElapsed_time() const {
    if (running) {  // If the stopwatch is still running
        return getProcessTime() - begin_time;  // Return the time elapsed since the start
    }
    return end_time - begin_time;  // Return the elapsed time between start and end
}

// Get the current process time in seconds
double StopWatch::getProcessTime() const {
    return static_cast<double>(clock()) / CLOCKS_PER_SEC;  // Convert clock ticks to seconds
}

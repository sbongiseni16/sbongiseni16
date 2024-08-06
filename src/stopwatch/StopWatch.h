#ifndef STOPWATCH_H
#define STOPWATCH_H

// StopWatch class for measuring elapsed time
class StopWatch {
public:
    // Constructor to initialize the stopwatch
    StopWatch();

    // Start the stopwatch
    void begin();

    // Stop the stopwatch
    void end();

    // Reset the stopwatch to zero
    void reset();

    // Fetch the elapsed time in seconds
    double fetchElapsed_time() const;

private:
    double begin_time;  // Store the start time of the stopwatch
    double end_time;    // Store the end time of the stopwatch
    bool running;       // Flag to check if the stopwatch is currently running

    // Get the current process time in seconds
    double getProcessTime() const;
};

#endif // STOPWATCH_H

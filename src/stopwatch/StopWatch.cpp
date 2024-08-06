#include <iostream>
#include <ctime>
#include "StopWatch.h"

stopwatch::stopwatch(){
            setProcessTime();
            std::cout << getProcessTime();
}
double stopwatch::getProcessTime(){
            return processTime;
}
void stopwatch::setProcessTime(){
            time_t start = time(nullptr);
            time_t end = time(nullptr);
            double elapsed_time = difftime(end, start);
            processTime = elapsed_time;
}



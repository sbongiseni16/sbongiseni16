#include <iostream>
#include <ctime>

class stopwatch{
    public:
        stopwatch();
        double getProcessTime();
        void setProcessTime();
    private:
        double processTime;

};


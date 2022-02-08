#pragma once
#include "thread.hpp"

class MeasurementsThread {
    public:
        MeasurementsThread();
    private:
        RTOSThread thread;
        static void measurementsRun(void *args);
};
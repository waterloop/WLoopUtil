#include "rtos_example.hpp"

MeasurementsThread::MeasurementsThread() {
    // I know this is bad btw
    this->thread = new RTOSThread(
        "Measurements thread",
        1024*5,
        osPriorityAboveNormal,
        this->measurementsRun
    );
}

void MeasurementsThread::measurementsRun(void* args) {
    while (1) {
        // Do the stuff and things
        osDelay(100);
    }
}
#include "rtos_example.hpp"

MeasurementsThread::MeasurementsThread() {
    this->thread = RTOSThread(
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
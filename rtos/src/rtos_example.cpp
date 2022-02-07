#include "rtos_example.hpp"

MeasurementsThread::MeasurementsThread() {
    // Now this seems stupid
    RTOSThread classThread(
        "Measurements thread",
        1024*5,
        osPriorityAboveNormal,
        this->measurementsRun
    );

    this->thread = &classThread;
}

void MeasurementsThread::measurementsRun(void* args) {
    while (1) {
        // Do the stuff and things
        osDelay(100);
    }
}
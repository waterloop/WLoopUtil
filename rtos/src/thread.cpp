#include "thread.hpp"

RTOSThread::RTOSThread(char const * name, uint32_t stack_size, osPriority_t priority, void callback(void* arg)) {
    const osThreadAttr_t thread_attrs = {
        .name = name,
        .stack_size = stack_size,
        .priority = priority
    };

    this->thread = osThreadNew(
        callback,
        NULL,
        &thread_attrs
    );

}

RTOSThread::RTOSThread() {}

osThreadId_t RTOSThread::getThreadId() {
    return this->thread;
}


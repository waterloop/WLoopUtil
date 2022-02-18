#pragma once
#include <string.h>
#include "cmsis_os.h"

class RTOSThread {
    public:
        RTOSThread();
        RTOSThread(char* name, uint32_t stack_size, osPriority_t priority, void callback(void* arg));  
        osThreadId_t getThreadId();    
    private:
        osThreadId_t thread;
};

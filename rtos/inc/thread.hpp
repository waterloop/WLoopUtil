#pragma once
#include <string.h>
#include "cmsis_os.h"

class RTOSThread {
    public:
        RTOSThread(char* name, uint32_t stack_size, osPriority_t priority, void callback(void* arg));    
    private:
        osThreadId_t thread;
};

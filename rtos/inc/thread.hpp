#pragma once
#include <string.h>
#include "cmsis_os.h"

typedef void (*RTOSCallback)(void*);

class RTOSThread {
    public:
        RTOSThread();

        // keeping this here to not break current builds,
        // depreciate this once all repos have been migrated
        RTOSThread(
            char const * name_, uint32_t stack_size_, osPriority_t priority_, RTOSCallback callback_);

        void create();

        void suspendThread();
        void resumeThread();

        uint32_t setFlag(uint32_t flag);

        osThreadId_t getThreadId();    

    protected:
        osThreadId_t thread_;

        const char* name;
        uint32_t stack_size;
        osPriority_t priority;
        RTOSCallback callback;
        void* callback_arg;
};

#pragma once
#include "thread.hpp"

class ExampleThread: public RTOSThread {
public:
        ExampleThread();
        void init();

        int var1;
        int var2;

    private:
        void run();
        static void _run_callback(void *this_);
};

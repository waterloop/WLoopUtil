#include <stdio.h>
#include "rtos_example.hpp"

ExampleThread::ExampleThread() {}

// the "init" method is separate from the constructor in order
// to prevent the location of "this" from changing after
// the constructor returns
void ExampleThread::init() {
    this->name = "example_thread";
    this->stack_size = 1024;
    this->priority = osPriorityAboveNormal;
    this->callback = MeasurementsThread::_run_callback;
    this->callback_arg = (void*)this;
    this->create();
}
void ExampleThread::_run_wrapper(void* this_) {
    ((ExampleThread*)this_)->_run();
}

void ExampleThread::run() {
    while (1) {
        printf("%d\r\n", this->var1);
        printf("%d\r\n", this->var2);

        osDelay(500);    
    }
}



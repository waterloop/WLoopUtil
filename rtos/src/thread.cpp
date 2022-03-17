#include "thread.hpp"

RTOSThread::RTOSThread() {}
RTOSThread::RTOSThread(
        char const * name_, uint32_t stack_size_, osPriority_t priority_, RTOSCallback callback_) {

    this->name = name_;
    this->stack_size = stack_size_;
    this->priority = priority_;
    this->callback = callback_;
    this->callback_arg = nullptr;
    this->create();
}

void RTOSThread::create() {
    const osThreadAttr_t thread_attrs = {
        .name = this->name,
        .stack_size = this->stack_size,
        .priority = this->priority
    };
    this->thread_ = osThreadNew(this->callback, (void*)this, &thread_attrs);
}

void RTOSThread::suspendThread() {
    osThreadSuspend(this->thread_);
}

void RTOSThread::resumeThread() {
    osThreadResume(this->thread_);
}

uint32_t RTOSThread::setFlag(uint32_t flag) {
    return osThreadFlagsSet(this, flag);
}

osThreadId_t RTOSThread::getThreadId() {
    return this->thread_;
}


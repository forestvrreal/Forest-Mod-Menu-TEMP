#include <jni.h>
#include <string>
#include <thread>
#include <chrono>
#include "BNM/Loading.hpp"

void loaded() {
    BNM_LOG_INFO("initialized bnm v%s", BNM_VER);
    // do all your initialized stuff here
}

__attribute__((constructor))
void init_main() {
    BNM::Loading::AllowLateInitHook();
    std::thread([]() {
        void* handle = nullptr;
        while (!handle) {
            handle = BNM_dlopen("libil2cpp.so", RTLD_LAZY);
            if (!handle) std::this_thread::sleep_for(std::chrono::milliseconds(250));
        }
        BNM::Loading::AddOnLoadedEvent(loaded);
        BNM::Loading::TryLoadByDlfcnHandle(handle);
    }).detach();
}
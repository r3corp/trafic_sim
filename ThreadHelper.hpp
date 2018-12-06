#ifndef THREAD_HELPER_HEADER
#define THREAD_HELPER_HEADER

#include <thread>

class ThreadHelper 
{    
private:
public:
    static void aguardar(int miliSegundos) 
    {
        std::this_thread::sleep_for (std::chrono::milliseconds(miliSegundos));
    }
};

#endif
//
// Created by pbeerken on 6/6/17.
//
#include "../Logger.h"
#include <thread>
#include <chrono>

int runningFromAnotherThread ()
{
    auto& test2=Logger::Instance().log ();
    test2<<"From another thread";
    std::this_thread::sleep_for (std::chrono::seconds (2));
    Logger::Instance().log ()<<" after the pause";
};



int main ()
{
    auto& test=Logger::Instance().log ();
    test<<LogStream::endl;
    test<<"Hello World "<<123.4<<" see ya"<<LogStream::endl;

    std::thread t (runningFromAnotherThread);
    t.join ();


    return 0;
}
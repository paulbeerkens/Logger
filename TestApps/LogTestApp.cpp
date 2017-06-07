//
// Created by pbeerken on 6/6/17.
//
#include "../Logger.h"
#include <thread>
#include <chrono>

int runningFromAnotherThread ()
{
    auto &test2 = Logger::Instance().logInfo();
    test2<<"From another thread";
    std::this_thread::sleep_for (std::chrono::seconds (2));
    Logger::Instance().logInfo() << " after the pause" << LogStream::endl;
};



int main ()
{
    auto &test = Logger::Instance().logInfo();
    test<<"Hi2"<<LogStream::endl;
    test<<"Hello World "<<123.4<<" see ya"<<LogStream::endl;

    std::thread t (runningFromAnotherThread);
    t.join ();


    return 0;
}

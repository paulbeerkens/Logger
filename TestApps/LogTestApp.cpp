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
    std::this_thread::sleep_for(std::chrono::seconds(1));
    Logger::Instance().logInfo() << " after the pause" << LogStream::endl;
};



int main ()
{
    auto &test = Logger::Instance().logInfo();
    test<<"Hi2"<<LogStream::endl;
    test<<"Hello World "<<123.4<<" see ya"<<LogStream::endl;

    Logger::Instance().logInfo() << "Direct writing";
    Logger::Instance().logInfo() << " and some more";
    Logger::Instance().logInfo() << LogStream::endl;

    Logger::Instance().logError() << "An error" << LogStream::endl;
    Logger::Instance().logWarning() << "A warning" << LogStream::endl;

    std::thread t (runningFromAnotherThread);
    t.join ();


    std::string s = "Hello";
    std::string s2(s.c_str(), 5);
    Logger::Instance().logInfo() << "A string " << s2 << LogStream::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;
}

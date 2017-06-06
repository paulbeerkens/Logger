//
// Created by pbeerken on 6/6/17.
//

#ifndef LIBLOG_LOGSTREAM_H
#define LIBLOG_LOGSTREAM_H

#include <iostream>
#include <thread>
#include <memory>
#include "LogLine.h"
#include "LogPolicy.h"

class LogStream {
public:
    enum Control {endl=0};

    LogStream ()
    {
        std::cout<<"Created LogStream"<<this<<" from :"<<std::this_thread::get_id()<<std::endl;
    };
    ~LogStream ()
    {
        std::cout<<"Destroyed LogSteam: "<<this<<" from:"<<std::this_thread::get_id()<<std::endl;
    };
    template <typename T> LogStream& operator << (const T& v)
    {
        if (logLine_==nullptr) logLine_=getLogLine ();
        *logLine_<<v;
        return *this;
    };

    std::unique_ptr <LogLine> getLogLine ()
    {
        return std::make_unique <LogLine> ();
    }


    static void setLogPolicy (LogPolicy* logPolicy)
    {
        logPolicy_=logPolicy;
    }

    static LogPolicy* logPolicy_;
protected:
    std::unique_ptr <LogLine> logLine_=nullptr; //unique_ptr is very slow. Should change to raw pointer if speed increase is required


};


template <>
LogStream&
LogStream::operator << <LogStream::Control> (const LogStream::Control& c);



#endif //LIBLOG_LOGSTREAM_H

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
#include "LogSeverity.h"
#include <sys/syscall.h>
#include <unistd.h>

class LogStream {
public:
    enum Control {endl=0};


    LogStream ()
    {
        //std::cout<<"Created LogStream"<<this<<" from :"<<std::this_thread::get_id()<<std::endl;
        tid_ = syscall(SYS_gettid);
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

    void setSeverityAndTimeIfRequired(LogSeverity s) {
        if (logLine_ == nullptr) logLine_ = getLogLine();
        logLine_->setSeverityAndTimeIfRequired(s);
    }

    std::unique_ptr<LogLine> getLogLine() {//create a memory pool if this function is called a lot
        std::unique_ptr<LogLine> logLine = std::make_unique<LogLine>();
        logLine->setTid(tid_);
        return logLine;
    }


    static void setLogPolicy (LogPolicy* logPolicy)
    {
        logPolicy_=logPolicy;
    }

    static LogPolicy* logPolicy_;
protected:
    std::unique_ptr <LogLine> logLine_=nullptr; //unique_ptr is very slow. Should change to raw pointer if speed increase is required
    long tid_; //thread id



};


template <>
LogStream&
LogStream::operator << <LogStream::Control> (const LogStream::Control& c);



#endif //LIBLOG_LOGSTREAM_H

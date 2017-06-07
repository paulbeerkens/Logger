//
// Created by pbeerken on 6/6/17.
//

#ifndef LIBLOG_LOGLINE_H
#define LIBLOG_LOGLINE_H

#include <sstream>
#include <iostream>
#include <assert.h>
#include "LogSeverity.h"
#include <chrono>
#include <iomanip> //for std::put_time
#include <string>

class LogLine {
public:
    ~LogLine ()
    {
        assert (ss_.str ().empty()); //this means that we did not use <<LogStream::endl in this thread
    }

    template <typename T> void operator << (T&v)
    {
        ss_<<v;
    }

    std::string asString() const;

    void reset ();

    void setSeverityAndTimeIfRequired(LogSeverity s) {
        currentSeverity_ = s;
        if (!timeSet_) {
            timeStamp_ = std::chrono::system_clock::now();
        }
    };


    void setTid(long tid) {
        tid_ = tid;
    }

protected:
    bool timeSet_ = false;
    std::stringstream ss_;
    LogSeverity currentSeverity_ = LogSeverity::NotSet;
    std::chrono::system_clock::time_point timeStamp_;
    long tid_ = -1; //thread id
};


#endif //LIBLOG_LOGLINE_H

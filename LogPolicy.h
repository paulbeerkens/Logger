//
// Created by pbeerken on 6/6/17.
//

#ifndef LIBLOG_LOGPOLICY_H
#define LIBLOG_LOGPOLICY_H

#include <memory>

class LogLine;


class LogPolicy {
public:
    virtual ~LogPolicy()=default;
    virtual void log (std::unique_ptr<LogLine>& logLine)=0;
};


#endif //LIBLOG_LOGPOLICY_H

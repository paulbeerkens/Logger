//
// Created by pbeerken on 6/6/17.
//

#ifndef LIBLOG_LOGCOUTPOLICY_H
#define LIBLOG_LOGCOUTPOLICY_H

#include "LogPolicy.h"

class LogDirectCoutPolicy: public LogPolicy {
public:
    void log (std::unique_ptr<LogLine>& logLine) override;

};


#endif //LIBLOG_LOGCOUTPOLICY_H

//
// Created by pbeerken on 6/7/17.
//

#ifndef LIBLOG_LOGSEVERITY_H
#define LIBLOG_LOGSEVERITY_H

#include <string>

enum LogSeverity {
    NotSet = 0, Debug = 1, Info, Warning, Error
};

const std::string &toString(LogSeverity ls);

#endif //LIBLOG_LOGSEVERITY_H

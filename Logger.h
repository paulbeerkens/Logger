//
// Created by pbeerken on 6/6/17.
//

#ifndef LIBLOG_LOGGER_H
#define LIBLOG_LOGGER_H

#include "LogStream.h"

class Logger {
public:
    static Logger& Instance ()
    {
        static Logger logger;
        return logger;
    }
    LogStream& log ()
    {
        thread_local LogStream logStream;
        return logStream;
    };
protected:
    Logger ();
};


#endif //LIBLOG_LOGGER_H

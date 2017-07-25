//
// Created by pbeerken on 6/6/17.
//

#ifndef LIBLOG_LOGGER_H
#define LIBLOG_LOGGER_H

#include "LogStream.h"
#include "LogSeverity.h"

class Logger {
public:


    static Logger& Instance ()
    {
        static Logger logger;
        return logger;
    }

    LogStream &logInfo()
    {
        thread_local LogStream logStream;
        logStream.setSeverityAndTimeIfRequired(LogSeverity::Info);
        return logStream;
    };

    LogStream &logError()
    {
        thread_local LogStream logStream;
        logStream.setSeverityAndTimeIfRequired(LogSeverity::Error);
        return logStream;
    }
protected:

    Logger ();
};


#endif //LIBLOG_LOGGER_H

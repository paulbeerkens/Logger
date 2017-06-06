//
// Created by pbeerken on 6/6/17.
//

#include "Logger.h"
#include "LogDirectCoutPolicy.h"

//static
//LogStream Logger::logStream_;

Logger::Logger ()
{
    LogStream::logPolicy_=new LogDirectCoutPolicy;
}

/*
LogStream& Logger::log ()
{
    thread_local LogStream logStream;
    return logStream;
};
 */

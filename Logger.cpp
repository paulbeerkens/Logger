//
// Created by pbeerken on 6/6/17.
//

#include "Logger.h"

//static
//LogStream Logger::logStream_;


LogStream& Logger::log ()
{
    thread_local LogStream logStream;
    return logStream;
};

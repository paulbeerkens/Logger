//
// Created by pbeerken on 6/6/17.
//

#include "LogCoutPolicy.h"
#include "LogLine.h"
//#include <iostream>

void LogCoutPolicy::log(std::unique_ptr<LogLine> &logLine)
{
    std::cout<<logLine->asString ()<<std::endl;
    logLine.reset (nullptr);
}

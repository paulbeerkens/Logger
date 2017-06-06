//
// Created by pbeerken on 6/6/17.
//

#include "LogDirectCoutPolicy.h"
#include "LogLine.h"
//#include <iostream>

void LogDirectCoutPolicy::log(std::unique_ptr<LogLine> &logLine)
{
    std::cout<<logLine->asString ()<<std::endl;
    //logLine.reset (nullptr); //This will force a new logline to be created
    logLine->reset (); //prepare the logline to be used again. Only if we hand over the line to another thread do we need to force the creation of a new line

}

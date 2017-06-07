//
// Created by pbeerken on 6/7/17.
//

#include "LogSeverity.h"
#include "assert.h"

const std::string &toString(LogSeverity ls) {
    switch (ls) {
        case NotSet:
            static std::string NotSetStr("NotSet");
            return NotSetStr;
        case Debug:
            static std::string DebugStr("Debug");
            return DebugStr;
        case Info:
            static std::string InfoStr("Info");
            return InfoStr;
        case Warning:
            static std::string WarningStr("Warn");
            return WarningStr;
        case Error:
            static std::string ErrorStr("Error");
            return ErrorStr;


    };
    static std::string UnknownStr("Unknown");
    assert (false); //should never reach this
    return UnknownStr;
}
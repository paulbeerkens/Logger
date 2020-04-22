//
// Created by pbeerken on 6/6/17.
//

#include "LogLine.h"

void LogLine::reset() {
    ss_.str ("");
    timeSet_ = false;
}

std::string
LogLine::asString() const {
    //First the header
    std::stringstream ss;

    //print the date and time
    std::time_t timet = std::chrono::system_clock::to_time_t(timeStamp_);
    std::tm *lt = std::localtime(&timet);
    ss << std::put_time(lt, "%y%m%d|%H%M%S");

    //miliseconds
    std::chrono::system_clock::duration tp = timeStamp_.time_since_epoch();
    tp -= std::chrono::duration_cast<std::chrono::seconds>(tp);
    ss << "." << static_cast<unsigned>(tp / std::chrono::milliseconds(1));

    //print the severity
    ss << "|" << toString(currentSeverity_);
    //Add the thread id
    ss << "|" << tid_ << "|";

    //Then the actual line we are supposed to log
    ss << ss_.str() << std::endl;
    return ss.str();
}


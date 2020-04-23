//
// Created by pbeerkens on 4/23/20.
//

#ifndef LIBLOG_LOGMACROS_H
#define LIBLOG_LOGMACROS_H

#include "Logger.h"

#define LOGINFO(S)Logger::Instance().logInfo()<<S<<LogStream::endl;
#define LOGWARN(S)Logger::Instance().logWarning()<<S<<LogStream::endl;
#define LOGERROR(S)Logger::Instance().logError()<<S<<LogStream::endl;

#endif //LIBLOG_LOGMACROS_H

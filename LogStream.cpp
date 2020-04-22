//
// Created by pbeerken on 6/6/17.
//

#include "LogStream.h"
#include <assert.h>

//static
LogPolicy* LogStream::logPolicy_=nullptr;

template <>
LogStream&
LogStream::operator << <LogStream::Control> (const LogStream::Control& )
{
    assert (logPolicy_!=nullptr);
    logPolicy_->log (logLine_);

    return *this;
}
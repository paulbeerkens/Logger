//
// Created by pbeerken on 6/6/17.
//

#ifndef LIBLOG_LOGLINE_H
#define LIBLOG_LOGLINE_H

#include <sstream>
#include <iostream>
#include <assert.h>

class LogLine {
public:
    LogLine ()
    {
        std::cout<<"Log line created"<<std::endl;
    }
    ~LogLine ()
    {
        std::cout<<"Log line destroyed"<<std::endl;
        assert (ss_.str ().empty()); //this means that we did not use <<LogStream::endl in this thread
    }

    template <typename T> void operator << (T&v)
    {
        ss_<<v;
        //std::cout<<" so far: "<<ss_.str ()<<std::endl;
    }

    const std::string asString () {return ss_.str ();};

    void reset ();

protected:
    //TODO add time and log level
    std::stringstream ss_;
};


#endif //LIBLOG_LOGLINE_H

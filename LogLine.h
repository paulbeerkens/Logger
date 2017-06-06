//
// Created by pbeerken on 6/6/17.
//

#ifndef LIBLOG_LOGLINE_H
#define LIBLOG_LOGLINE_H

#include <sstream>
#include <iostream>

class LogLine {
public:
    LogLine ()
    {
        std::cout<<"Log line created"<<std::endl;
    }
    ~LogLine ()
    {
        std::cout<<"Log line destroyed"<<std::endl;
    }

    template <typename T> void operator << (T&v)
    {
        ss_<<v;
        std::cout<<" so far: "<<ss_.str ()<<std::endl;
    }
protected:
    std::stringstream ss_;
};


#endif //LIBLOG_LOGLINE_H

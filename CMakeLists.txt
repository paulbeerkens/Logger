cmake_minimum_required(VERSION 3.7)
project(libLog)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Logger.cpp Logger.h LogStream.cpp LogStream.h LogLine.cpp LogLine.h LogPolicy.cpp LogPolicy.h LogDirectCoutPolicy.cpp LogDirectCoutPolicy.h LogSeverity.h LogSeverity.cpp)
add_library(libLog ${SOURCE_FILES})


####### Unit Tests ##############
set (GTEST_ROOT /usr)
find_package(GTest REQUIRED)

######## Test App ################
add_executable (LogThreadApp TestApps/LogTestApp.cpp)
find_package (Threads)
target_link_libraries(LogThreadApp ${CMAKE_THREAD_LIBS_INIT} libLog)
#target_link_libraries(LogThreadApp ${CMAKE_THREAD_LIBS_INIT} )
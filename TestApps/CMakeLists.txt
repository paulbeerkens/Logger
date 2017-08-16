add_executable(LogThreadApp LogTestApp.cpp)
find_package(Threads)
target_link_libraries(LogThreadApp ${CMAKE_THREAD_LIBS_INIT} libLog)
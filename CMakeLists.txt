cmake_minimum_required(VERSION 3.7)
project(libLog)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Logger.cpp Logger.h LogStream.cpp LogStream.h LogLine.cpp LogLine.h LogPolicy.cpp LogPolicy.h LogDirectCoutPolicy.cpp LogDirectCoutPolicy.h LogSeverity.h LogSeverity.cpp)
add_library(libLog ${SOURCE_FILES})


file(GLOB HEADERS *.h)
install(FILES ${HEADERS} DESTINATION ~/source/pkg/include/${PROJECT_NAME})
install(TARGETS ${PROJECT_NAME} DESTINATION ~/source/pkg/lib)

add_custom_target(install_${PROJECT_NAME}
        $(MAKE) install
        DEPENDS ${PROJECT_NAME}
        COMMENT "Installing ${PROJECT_NAME}")

####### Unit Tests ##############
set (GTEST_ROOT /usr)
find_package(GTest REQUIRED)
set(UnitTest_SOURCE_FILES GTest/Main.cpp GTest/LogTests.cpp)
add_executable(UnitTest ${UnitTest_SOURCE_FILES})
target_link_libraries(UnitTest GTest::GTest GTest::Main libLog)
#target_link_libraries(LogThreadApp ${CMAKE_THREAD_LIBS_INIT} libLog)

######## Test App ################
add_executable (LogThreadApp TestApps/LogTestApp.cpp)
find_package (Threads)
target_link_libraries(LogThreadApp ${CMAKE_THREAD_LIBS_INIT} libLog)
#target_link_libraries(LogThreadApp ${CMAKE_THREAD_LIBS_INIT} )
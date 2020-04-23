cmake_minimum_required(VERSION 3.7)
project(libLog)

#do not append lib to library name
set(CMAKE_STATIC_LIBRARY_PREFIX "")

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        LogDirectCoutPolicy.h
        Logger.h
        LogMacros.h
        LogStream.h
        LogLine.h
        LogPolicy.h
        LogSeverity.h
        )

set(SOURCE_FILES
        LogDirectCoutPolicy.cpp
        Logger.cpp
        LogStream.cpp
        LogLine.cpp
        LogPolicy.cpp
        LogSeverity.cpp)


add_library(libLog STATIC ${SOURCE_FILES})


target_include_directories (libLog INTERFACE ../.) #Allow to include this to be included with the directory eg #include <Logger/Logger.H>

#file(GLOB HEADERS *.h)
#install(FILES ${HEADERS} DESTINATION ~/source/pkg/include/${PROJECT_NAME})
#install(TARGETS ${PROJECT_NAME} DESTINATION ~/source/pkg/lib)

#add_custom_target(install_${PROJECT_NAME}
#        $(MAKE) install
#        DEPENDS ${PROJECT_NAME}
#        COMMENT "Installing ${PROJECT_NAME}")

####### Unit Tests ##############
add_subdirectory(GTest)

######## Test App ################
add_subdirectory(TestApps)
cmake_minimum_required(VERSION 3.7)
project(libLog)

#do not append lib to library name
set(CMAKE_STATIC_LIBRARY_PREFIX "")

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
add_subdirectory(GTest)


######## Test App ################
add_subdirectory(TestApps)
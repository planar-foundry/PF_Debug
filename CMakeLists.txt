cmake_minimum_required(VERSION 3.8)
project(PF_Debug VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

option(PFDEBUG_BUILD_TESTS "Builds all unit tests" OFF)
option(PFDEBUG_ENABLE_ASSERT "Enables the assert output" ON)
option(PFDEBUG_ENABLE_LOG "Enables the log output" ON)

add_subdirectory(ext)
add_subdirectory(src)

if (${PFDEBUG_BUILD_TESTS})
    add_subdirectory(tests)
endif()

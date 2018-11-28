cmake_minimum_required(VERSION 3.6)

project(lab3-postfix)

include(cmake/function.cmake)

add_subdirectory(parser)
add_subdirectory(sample)

option(BTEST "build test?" OFF)

if(BTEST)
    add_subdirectory(gtest)
    add_subdirectory(test)
endif()

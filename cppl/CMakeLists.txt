cmake_minimum_required(VERSION 3.10)
project(CppLearn)
aux_source_directory(. SRC_LIST)
add_executable(cppl main.cpp ${SRC_LIST})

option(TARGET_PLATFORM "Specify the target platform (Linux/Windows)" "")
if(TARGET_PLATFORM STREQUAL "Linux")
    set(CMAKE_CXX_COMPILER "g++")
elseif(TARGET_PLATFORM STREQUAL "Windows")
    set(CMAKE_CXX_COMPILER "x86_64-w64-mingw32-g++")  # 在Linux下使用MinGW的g++编译器
else()
    message(FATAL_ERROR "Invalid target platform specified. Please specify Linux or Windows.")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

cmake_minimum_required(VERSION 3.10)

project(hpCardGame VERSION 0.0.1)

add_executable(hpGame lib.cpp main.cpp)

option(TARGET_PLATFORM "Specify the target platform (Linux/Windows)" "")

#target_link_libraries(hpGame PRIVATE ncursesw)

# 根据传入的参数选择不同的编译器
if(TARGET_PLATFORM STREQUAL "Linux")
    set(CMAKE_CXX_COMPILER "g++")
elseif(TARGET_PLATFORM STREQUAL "Windows")
    set(CMAKE_CXX_COMPILER "x86_64-w64-mingw32-g++")  # 在Linux下使用MinGW的g++编译器
else()
    message(FATAL_ERROR "Invalid target platform specified. Please specify Linux or Windows.")
endif()

# 查找ncursesw库
find_library(NCURSESW_LIBRARY NAMES ncursesw)
if(NCURSESW_LIBRARY)
    message(STATUS "Found ncursesw library: ${NCURSESW_LIBRARY}")
else()
    message(FATAL_ERROR "ncursesw library not found")
endif()

set(CMAKE_FIND_LIBRARY_SUFFIXES .a ${CMAKE_FIND_LIBRARY_SUFFIXES})

# 查找tinfo库
#set(TINFO_LIBRARY /usr/lib/x86_64-linux-gnu/libtinfo.a)
find_library(TINFO_LIBRARY NAMES tinfo)

# 设置编译选项，启用静态链接
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

# 链接ncursesw库和tinfo库
target_link_libraries(hpGame ${NCURSESW_LIBRARY} ${TINFO_LIBRARY})



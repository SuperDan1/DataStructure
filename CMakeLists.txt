cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(data-structure CXX)

# enable c++ 11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# take respectives flags for debug & release process 
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-std=c++17 -g -fno-omit-frame-pointer 
-fsanitize=address")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-std=c++17 -g -O2")

# default build type : Debug
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_subdirectory(main)
add_subdirectory(List)
#add_subdirectory(Graph)
#add_subdirectory(Tree)

# CTest related
enable_testing()
add_subdirectory(tests)

project(lab07)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(test)

add_executable(main main.cpp)
target_link_libraries(main src_lib)
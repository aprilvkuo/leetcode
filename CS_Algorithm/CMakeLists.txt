cmake_minimum_required(VERSION 3.14)
project(Algorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)


aux_source_directory(src DIR_SRCS)

add_executable(Algorithm main.cpp ${DIR_SRCS})

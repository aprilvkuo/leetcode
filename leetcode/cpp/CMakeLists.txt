cmake_minimum_required(VERSION 3.7.2)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

#SET(SOURCE ${PROJECT_SOURCE_DIR}/src/*.cpp )

INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(tmp)


add_executable(leetcode main.cpp ${SOURCE})
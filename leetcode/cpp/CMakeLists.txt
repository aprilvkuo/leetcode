cmake_minimum_required(VERSION 3.14)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

SET(SOURCE ${PROJECT_SOURCE_DIR}/src/coding_interviews.cpp)
INCLUDE_DIRECTORIES(include)


add_executable(leetcode main.cpp ${SOURCE})
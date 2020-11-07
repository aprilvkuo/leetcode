cmake_minimum_required(VERSION 3.7.2)
project(nowcoder)

set(CMAKE_CXX_STANDARD 14)

SET(NOW_SOURCE ${PROJECT_SOURCE_DIR}/nowcoder/cpp/src/*.cpp)
SET(LEET_SOURCE ${PROJECT_SOURCE_DIR}/leetcode/cpp/src/*.cpp )

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/nowcoder/cpp/include  ${PROJECT_SOURCE_DIR}/nowcoder/cpp/include)

add_executable(test_demo main.cpp)
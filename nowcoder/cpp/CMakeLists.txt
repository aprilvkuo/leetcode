cmake_minimum_required(VERSION 3.7.2)
project(nowcoder)

set(CMAKE_CXX_STANDARD 14)

#SET(SOURCE ${PROJECT_SOURCE_DIR}/src/*.cpp )

INCLUDE_DIRECTORIES(include)


add_executable(nowcoder main.cpp ${SOURCE})
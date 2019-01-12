cmake_minimum_required(VERSION 2.8)
project(json_utils)

include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)
file(GLOB SOURCES "src/*.cpp")

add_executable(test ${SOURCES})
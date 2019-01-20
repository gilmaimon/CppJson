cmake_minimum_required(VERSION 2.8)
project(json_utils)

include_directories(include)
include_directories(catch2)

set(CATCH_HEADER "catch2/catch.hpp")
file(GLOB SOURCES "src/*.cpp")
file(GLOB TESTS "test/*.cpp")

add_executable(main ${SOURCES})

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_HEADER})

add_executable(tests ${TESTS})
target_link_libraries(tests Catch)

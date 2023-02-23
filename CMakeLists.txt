cmake_minimum_required(VERSION 3.13)
project(log)

file(GLOB_RECURSE SRC "src/*.cpp" "lib/*.cpp")

add_executable(log ${SRC})

target_include_directories(log PRIVATE "lib/")
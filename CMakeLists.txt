cmake_minimum_required(VERSION 3.3)
project(practice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.h main.c lib/baseArrayCreat.c lib/baseArrayCreat.h lib/printArray.c lib/printArray.h lib/swapVariables.c lib/swapVariables.h lib/gcd.c lib/gcd.h lib/max.c lib/max.h lib/createPrime.c lib/createPrime.h lib/baseGraphCreate.c lib/baseGraphCreate.h)
add_executable(practiceResult ${SOURCE_FILES})
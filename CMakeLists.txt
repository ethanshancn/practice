cmake_minimum_required(VERSION 3.3)
project(practice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.h main.c lib/baseArrayCreat.c lib/baseArrayCreat.h examples/maxSubSequenceSum.c examples/maxSubSequenceSum.h lib/printArray.c lib/printArray.h examples/sortProblem.c examples/sortProblem.h)
add_executable(practiceResult ${SOURCE_FILES})
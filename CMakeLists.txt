cmake_minimum_required(VERSION 3.3)
project(practice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.h main.c lib/baseArrayCreat.c lib/baseArrayCreat.h examples/maxSubSequenceSum.c examples/maxSubSequenceSum.h lib/printArray.c lib/printArray.h examples/sortProblem.c examples/sortProblem.h lib/swapVariables.c lib/swapVariables.h examples/searchProblem.c examples/searchProblem.h lib/gcd.c lib/gcd.h examples/list.c examples/list.h examples/polynomial.c examples/polynomial.h lib/max.c lib/max.h examples/stackList.c examples/stackList.h examples/stackArray.c examples/stackArray.h)
add_executable(practiceResult ${SOURCE_FILES})
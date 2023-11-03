cmake_minimum_required (VERSION 3.13)

project (DataStructures VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#
# Tell MSVC to build using multiple processes.
# This may speed up compilation time significantly.
# For more information check:
# https://learn.microsoft.com/en-us/cpp/build/reference/mp-build-with-multiple-processes?view=msvc-170
#
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

add_subdirectory(include)

option(BUILD_TESTS "Whether or not to build tests" ON)
option(BUILD_EXAMPLES "Whether or not to build examples" ON)


if (BUILD_TESTS)
    message(STATUS "Building tests...")
    add_subdirectory(tests)
endif()
if (BUILD_EXAMPLES)
    message(STATUS "Building examples...")
    add_subdirectory(example)
endif()
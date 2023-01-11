project(
    Test
    LANGUAGES CXX)

cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_STANDARD 17)

# Setup testing
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

set(SOURCES MergeSort.cpp QuickSort.cpp)
add_executable (unittest main.cpp
                         Utils.cpp
                         MergeSort.cpp
                         QuickSort.cpp)

# Link test executable against gtest & gtest_main
target_link_libraries(unittest GTest::GTest GTest::Main)

set(SOURCES MergeSort.cpp QuickSort.cpp)
foreach(test ${SOURCES})
    set(test_name ${test}_ctest)
    add_executable(${test_name} Utils.cpp ${test})
    target_link_libraries(${test_name} GTest::GTest GTest::Main)
    add_test(${test_name} ${test_name})
endforeach()

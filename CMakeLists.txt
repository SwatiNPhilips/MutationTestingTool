project(
    MutationTestingTool
    LANGUAGES CXX)

cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)

# all *.cpp from src folder are our source
file(GLOB_RECURSE SOURCES SRC/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

# include directories
target_include_directories(${PROJECT_NAME} PUBLIC INC)

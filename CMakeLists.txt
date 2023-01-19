project(
    MutationTestingTool
    LANGUAGES CXX)

cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)

# all *.cpp from src folder are our source
file(GLOB_RECURSE SOURCES SRC/*.cpp)

find_package(Boost 1.71 COMPONENTS filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
add_executable(${PROJECT_NAME} ${SOURCES})

# include directories
target_include_directories(${PROJECT_NAME} PUBLIC INC)

target_link_libraries(${PROJECT_NAME} PUBLIC Boost::filesystem)

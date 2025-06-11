cmake_minimum_required(VERSION 3.10.0)
project(logs-t2 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(logs-t2 ${SRC_FILES})
target_include_directories(logs-t2 PRIVATE ${PROJECT_SOURCE_DIR}/include)
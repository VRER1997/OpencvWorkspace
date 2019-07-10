cmake_minimum_required(VERSION 3.13)
project(chapter_03)

set(CMAKE_CXX_STANDARD 14)

find_package(Opencv REQUIRED)
include_directories(/usr/local/include)

add_executable(one_03 one.cpp)
add_executable(two_03 two.cpp)

target_link_libraries(one_03 ${OpenCV_LIBS})
target_link_libraries(two_03 ${OpenCV_LIBS})
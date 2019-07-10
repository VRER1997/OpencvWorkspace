cmake_minimum_required(VERSION 3.13)
project(chapter_01)

set(CMAKE_CXX_STANDARD 14)

find_package(Opencv REQUIRED)
include_directories(/usr/local/include)

add_executable(one one.cpp)
add_executable(two two.cpp)
add_executable(three three.cpp)
add_executable(four four.cpp)
add_executable(five five.cpp)

target_link_libraries(one ${OpenCV_LIBS})
target_link_libraries(two ${OpenCV_LIBS})
target_link_libraries(three ${OpenCV_LIBS})
target_link_libraries(four ${OpenCV_LIBS})
target_link_libraries(five ${OpenCV_LIBS})

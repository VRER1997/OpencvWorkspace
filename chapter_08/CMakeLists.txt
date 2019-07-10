CMAKE_MINIMUM_REQUIRED(VERSION 3.13)

project(chapter_08)

set(CMAKE_CXX_STANDARD 14)
find_package(Opencv REQUIRED)
include_directories(/usr/local/include)

add_executable(one_08 one.cpp)
add_executable(two_08 two.cpp)
add_executable(three_08 three.cpp)

target_link_libraries(one_08 ${OpenCV_LIBS})
target_link_libraries(two_08 ${OpenCV_LIBS})
target_link_libraries(three_08 ${OpenCV_LIBS})

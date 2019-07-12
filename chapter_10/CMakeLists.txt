CMAKE_MINIMUM_REQUIRED(VERSION 3.13)

project(chapter_10)

set(CMAKE_CXX_STANDARD 14)
find_package(Opencv REQUIRED)
include_directories(/usr/local/include)

add_executable(one_10 one.cpp)
add_executable(two_10 two.cpp)
add_executable(three_10 three.cpp)

target_link_libraries(one_10 ${OpenCV_LIBS})
target_link_libraries(two_10 ${OpenCV_LIBS})
target_link_libraries(three_10 ${OpenCV_LIBS})

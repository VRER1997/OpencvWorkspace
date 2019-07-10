cmake_minimum_required(VERSION 3.13)

project(chapter_06)

set(CMAKE_CXX_STANDARD 14)
find_package(Opencv REQUIRED)
include_directories(/usr/local/include)

add_executable(one_06 one.cpp)
add_executable(two_06 two.cpp)
add_executable(three_06 three.cpp)
add_executable(four_06 four.cpp)
add_executable(five_06 five.cpp)
add_executable(six_06 six.cpp)

target_link_libraries(one_06 ${OpenCV_LIBS})
target_link_libraries(two_06 ${OpenCV_LIBS})
target_link_libraries(three_06 ${OpenCV_LIBS})
target_link_libraries(four_06 ${OpenCV_LIBS})
target_link_libraries(five_06 ${OpenCV_LIBS})
target_link_libraries(six_06 ${OpenCV_LIBS})

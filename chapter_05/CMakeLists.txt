cmake_minimum_required(VERSION 3.13)
project(test)

set(CMAKE_CXX_STANDARD 14)

find_package(Opencv REQUIRED)
include_directories(/usr/local/include)

add_executable(one_05 one.cpp)
add_executable(two_05 two.cpp)
add_executable(three_05 three.cpp)
add_executable(four_05 four.cpp)
add_executable(five_05 five.cpp)
add_executable(six_05 six.cpp)

target_link_libraries(one_05 ${OpenCV_LIBS})
target_link_libraries(two_05 ${OpenCV_LIBS})
target_link_libraries(three_05 ${OpenCV_LIBS})
target_link_libraries(four_05 ${OpenCV_LIBS})
target_link_libraries(five_05 ${OpenCV_LIBS})
target_link_libraries(six_05 ${OpenCV_LIBS})

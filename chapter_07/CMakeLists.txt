cmake_minimum_required(VERSION 3.13)

project(chapter_07)

set(CMAKE_CXX_STANDARD 14)
find_package(Opencv REQUIRED)
include_directories(/usr/local/include)

add_executable(one_07 one.cpp)
add_executable(two_07 two.cpp)
add_executable(three_07 three.cpp)
add_executable(four_07 four.cpp)
add_executable(five_07 five.cpp)
add_executable(six_07 six.cpp)
add_executable(seven_07 seven.cpp)

target_link_libraries(one_07 ${OpenCV_LIBS})
target_link_libraries(two_07 ${OpenCV_LIBS})
target_link_libraries(three_07 ${OpenCV_LIBS})
target_link_libraries(four_07 ${OpenCV_LIBS})
target_link_libraries(five_07 ${OpenCV_LIBS})
target_link_libraries(six_07 ${OpenCV_LIBS})
target_link_libraries(seven_07 ${OpenCV_LIBS})

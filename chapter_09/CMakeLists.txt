CMAKE_MINIMUM_REQUIRED(VERSION 3.13)

project(chapter_09)

set(CMAKE_CXX_STANDARD 14)
find_package(Opencv REQUIRED)
include_directories(/usr/local/include)

add_executable(one_09 one.cpp)

target_link_libraries(one_09 ${OpenCV_LIBS})
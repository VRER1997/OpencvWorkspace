cmake_minimum_required(VERSION 3.13)
project(chapter_04)

set(CMAKE_CXX_STANDARD 14)
find_package(Opencv REQUIRED)
include_directories(/usr/local/include)

add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})

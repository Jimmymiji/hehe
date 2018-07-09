set (CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
cmake_minimum_required(VERSION 2.8)
project( haha )
find_package( OpenCV REQUIRED )
add_executable( haha main.cpp )
target_link_libraries( haha ${OpenCV_LIBS} )
target_link_libraries (haha ${CMAKE_THREAD_LIBS_INIT})


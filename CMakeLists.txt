cmake_minimum_required(VERSION 2.8)
project( BGM )
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package( OpenCV REQUIRED )
#find_package(OpenCV 3.4.5 EXACT REQUIRED PATHS "/home/somnath/opencv-3.4.5/build/")
add_executable(BGM BGM.cpp main.cpp)
target_link_libraries( BGM  ${OpenCV_LIBS} )


cmake_minimum_required(VERSION 3.17)
project(lab2_01)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2_01 main.cpp src/Point.cpp src/Point.hpp src/Segment.cpp src/Segment.hpp src/Broken.cpp src/Broken.hpp src/Closed.cpp src/Closed.hpp src/Polygon.cpp src/Polygon.hpp src/Triangle.cpp src/Triangle.hpp src/Vector.cpp src/Vector.hpp src/Trapezoid.cpp src/Trapezoid.hpp src/Regular.cpp src/Regular.hpp)
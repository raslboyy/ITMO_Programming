cmake_minimum_required(VERSION 3.17)
project(lab2_03)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2_03 main.cpp
        libs/pugixml/src/pugixml.hpp
        libs/pugixml/src/pugixml.cpp
        libs/pugixml/src/pugiconfig.hpp
        libs/StringPro/src/StringPro.hpp
        libs/StringPro/src/StringPro.cpp src/GeoPoint.cpp src/GeoPoint.hpp src/GeoObject.cpp src/GeoObject.hpp src/Station.cpp src/Station.hpp src/Street.cpp src/Street.hpp src/Route.cpp src/Route.hpp src/TramRoute.hpp src/BusRoute.hpp src/TrollRoute.hpp)
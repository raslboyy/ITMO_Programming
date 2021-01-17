cmake_minimum_required(VERSION 3.17)
project(lab1_13 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1_13 main.c MP3.h FrameID3v2.h FrameID3v2.c MP3.c)
#add_executable(lab1_13 main.c)
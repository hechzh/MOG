cmake_minimum_required(VERSION 3.9)
project(MOG)
find_package(GTest REQUIRED)
set(CMAKE_CXX_STANDARD 11)
ADD_SUBDIRECTORY(MOG)
ADD_SUBDIRECTORY(test)


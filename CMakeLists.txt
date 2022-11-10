cmake_minimum_required(VERSION 3.23)
project(ShelMaacompiler)

set(CMAKE_CXX_STANDARD 23)

add_executable(ShelMaacompiler main.cpp src/utils.cpp include/headers.h src/lexicalAnalysis.cpp src/commentHandling.cpp)

cmake_minimum_required(VERSION 3.20)

project(Assignment)

set(CMAKE_CXX_STANDARD 17)

add_executable(Analysis

        Analysis.cpp

        Problem1/BST.cpp
        Problem1/AVL.cpp

        Problem2/Heap.cpp
)

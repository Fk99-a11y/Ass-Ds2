cmake_minimum_required(VERSION 3.20)

project(Ass_Ds2)

set(CMAKE_CXX_STANDARD 17)

# ================= AVL =================
add_executable(AVLMain
        Problem1/AVL.cpp
        Problem1/AVLMain.cpp
)

# ================= BST =================
add_executable(BSTMain
        Problem2/BST.cpp
        Problem2/BSTMain.cpp
)

# ================= HEAP =================
add_executable(HeapMain
        Problem3/Heap.cpp
        Problem3/HeapMain.cpp
)

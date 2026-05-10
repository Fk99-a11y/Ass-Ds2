cmake_minimum_required(VERSION 3.20)
project(Ass_Ds2)

set(CMAKE_CXX_STANDARD 17)

# أضف مسار المجلد Problem1 (حتى يتمكن من العثور على AVL.h)
include_directories(Problem1)

# حدد الملفات المصدر (cpp فقط)
add_executable(AVLMain
        Problem1/AVL.cpp
        Problem1/AVLMain.cpp
)

target_sources(AVLMain PRIVATE Problem1/AVL.h)
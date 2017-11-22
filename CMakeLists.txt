cmake_minimum_required(VERSION 3.8)
project(dastr2)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp expression.cpp expression.h parser.cpp parser.h node.cpp node.h constants.h printer.cpp printer.h valid.cpp valid.h test.cpp test.h menu.cpp menu.h)
add_executable(dastr2 ${SOURCE_FILES})
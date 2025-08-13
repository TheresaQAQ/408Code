cmake_minimum_required(VERSION 3.27)
project(408Code C)

set(CMAKE_C_STANDARD 99)

add_executable(QuicklySort DS/Sort/QuicklySort.c)
add_executable(StackTest ./DS/StackAndQueue/StackTest.c)
add_executable(QueueTest ./DS/StackAndQueue/QueueTest.c)
add_executable(TreeTest ./DS/Tree/TreeTest.c)
add_executable(parenthesisMatch ./DS/StackAndQueue/parenthesisMatch.c)
cmake_minimum_required(VERSION 3.12)
project(C__)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(C__
        inputFiles/sampleHashTable1.txt
        inputFiles/sampleHeap1.txt
        inputFiles/sampleHeap2.txt
        outputFiles/sampleHashTable1.txt
        outputFiles/sampleHeap1.txt
        outputFiles/sampleHeap2.txt
        HashTable.cpp
        HashTable.h
        HeapPriorityQueue.cpp
        HeapPriorityQueue.h
        main.cpp)

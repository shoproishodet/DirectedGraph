cmake_minimum_required(VERSION 3.22)

add_executable(31_5_2
        main.cpp
        ${HEADERS_DIR}/IGraph.h
        MatrixGraph.cpp
        ${HEADERS_DIR}/MatrixGraph.h
        ListGraph.cpp
        ${HEADERS_DIR}/ListGraph.h)

target_include_directories(31_5_2 PUBLIC ${HEADERS_DIR})
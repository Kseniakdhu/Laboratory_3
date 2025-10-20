cmake_minimum_required(VERSION 3.30) 

project(Figure)

set(CMAKE_CXX_STANDARD 20) 

set(BINARY ${CMAKE_PROJECT_NAME})

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${INCLUDE_DIR})

add_library(${BINARY}_lib STATIC ${SOURCE_DIR}/Figure.cpp)

add_executable(${BINARY} main.cpp)

target_link_libraries(${BINARY} ${BINARY}_lib)

set_target_properties(${BINARY} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

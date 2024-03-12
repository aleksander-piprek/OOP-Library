cmake_minimum_required(VERSION 3.15)

project(library)

include_directories(include)

set(SOURCES "src/main.cpp"
            "include/library.hpp")

add_executable(library ${SOURCES})
target_link_libraries(library stdc++)
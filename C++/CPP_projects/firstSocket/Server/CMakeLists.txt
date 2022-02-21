cmake_minimum_required(VERSION 3.5)

project(ServerFile)

add_executable(server server.cpp)

set_target_properties(
    server PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
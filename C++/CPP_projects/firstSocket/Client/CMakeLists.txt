cmake_minimum_required(VERSION 3.5)

project(ClientFile)

add_executable(client client.cpp)

set_target_properties(
    client PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
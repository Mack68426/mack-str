cmake_minimum_required(VERSION 3.16)
project(MackStr)
################################
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

################################
add_library(
    mackstr
    mackstr/src/mcstr.c
    mackstr/include/mackstr/mcstr.h
)

target_include_directories(
    mackstr
    PUBLIC
        mackstr/include
)
#------------------------------#
add_library(
    core
    mackstr/core/include/base.h
)

target_include_directories(
    core
    PUBLIC
        mackstr/core/include
)

################################
add_executable(
    mack_floss
    mack_floss/src/main.c
)

###############################
target_link_libraries(
    mack_floss
    mackstr
)

#-----------------------------#
target_link_libraries(
    mackstr
    core
)

###############################

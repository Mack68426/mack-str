cmake_minimum_required(VERSION 3.15)
project(UUStr C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_executable(
    uustr,
    main.c,
    uustr.c,
    uustr.h,
    base.h
)
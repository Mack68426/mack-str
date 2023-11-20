cmake_minimum_required(VERSION 3.16)
project(MackStr)

set(CMAKE_INSTALL_PREFIX build/alpha)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# libraries
add_subdirectory(
    mackstr
)

add_subdirectory(mackstr)

# executable
add_subdirectory(mack_floss)

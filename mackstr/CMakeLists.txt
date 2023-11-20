add_library(
    mackstr
    src/mcstr.c
    include/mackstr/mcstr.h
    include/mackstr/base.h
)

target_include_directories(
    mackstr
    PUBLIC
        include
)

add_executable(
    mackstrtests
    tests/main.c
)



include(GNUInstallDirs)
install(
    DIRECTORY include/mackstr
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    TARGETS mackstr
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
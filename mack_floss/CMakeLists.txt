add_executable(
    mack_floss
    src/main.c
)

target_link_libraries(
    mack_floss
    mackstr
)


install(
    TARGETS mack_floss
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
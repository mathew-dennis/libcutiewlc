cmake_minimum_required(VERSION 3.16)
project(cutiewlc VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Core WaylandClient Quick)
qt_standard_project_setup()

include_directories(src)

set(lib_SOURCES
    src/wayland-cutie-shell.cpp 
    src/wayland-cutie-shell_p.h
    src/wayland-cutie-shell.h)

qt6_add_library(cutiewlc
    SHARED ${lib_SOURCES}
)

set_target_properties(cutiewlc PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(cutiewlc PROPERTIES SOVERSION 0)
set_target_properties(cutiewlc PROPERTIES PUBLIC_HEADER src/wayland-cutie-shell.h)

qt6_generate_wayland_protocol_client_sources(
    cutiewlc
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/protocols/cutie-shell-private.xml
)

target_link_libraries(cutiewlc PUBLIC
    Qt::Core
    Qt::WaylandClient
    Qt::Quick
)

configure_file(src/cutiewlc.pc.in cutiewlc.pc @ONLY)

install(TARGETS cutiewlc
    RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    BUNDLE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

install(FILES ${CMAKE_BINARY_DIR}/cutiewlc.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

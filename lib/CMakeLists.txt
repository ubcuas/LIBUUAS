cmake_minimum_required( VERSION 3.14 )
set( CMAKE_CXX_STANDARD 17 )
project( libuuas )

# Main libuuas so
add_library( uuas SHARED ${CMAKE_SOURCE_DIR}/src/libuuas/uuas.cpp )
target_include_directories( uuas PRIVATE ${CMAKE_SOURCE_DIR}/include/ )
target_compile_options( uuas PUBLIC "-Wall" )

# Install directives
include(GNUInstallDirs)
install(
    TARGETS uuas
    EXPORT uuas
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install (
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h*"
)

cmake_minimum_required( VERSION 3.14 )
set( CMAKE_CXX_STANDARD 17 )
project( libuuas )

# Libexiv2 dependency
include(FetchContent)
FetchContent_Declare( exiv2cmake URL https://www.exiv2.org/builds/exiv2-0.27.3-Source.tar.gz )
FetchContent_GetProperties( exiv2cmake )
if ( NOT exiv2cmake_POPULATED )
   FetchContent_Populate( exiv2cmake )
endif()
option( EXIV2_BUILD_SAMPLES "" OFF )
option( EXIV2_BUILD_EXIV2_COMMAND "" OFF )
add_subdirectory( ${exiv2cmake_SOURCE_DIR} ${exiv2cmake_BINARY_DIR} )

# Main libuuas so
add_library( uuas SHARED ${CMAKE_SOURCE_DIR}/src/libuuas/uuas.cpp )
target_include_directories( uuas PUBLIC ${CMAKE_SOURCE_DIR}/include/ ${exiv2cmake_SOURCE_DIR} )
target_link_libraries( uuas PUBLIC exiv2lib )
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

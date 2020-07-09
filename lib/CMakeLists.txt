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

# Protobuf dependency
FetchContent_Declare( protobufcmake URL https://github.com/protocolbuffers/protobuf/releases/download/v3.12.0/protobuf-cpp-3.12.0.tar.gz )
FetchContent_GetProperties( protobufcmake )
if ( NOT protobufcmake_POPULATED )
   FetchContent_Populate( protobufcmake )
endif()
option( protobuf_BUILD_TESTS "" OFF )
option( protobuf_BUILD_PROTOC_BINARIES "" OFF )
add_subdirectory( ${protobufcmake_SOURCE_DIR}/cmake ${protobufcmake_BINARY_DIR} )

# Main libuuas so
add_library( uuas SHARED ${CMAKE_SOURCE_DIR}/src/libuuas/uuas.cpp ${CMAKE_SOURCE_DIR}/src/libuuas/uuaspb.pb.cc )
target_include_directories( uuas PUBLIC ${CMAKE_SOURCE_DIR}/include/ )
target_link_libraries( uuas PUBLIC exiv2lib protobuf::libprotobuf )
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

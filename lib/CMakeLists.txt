cmake_minimum_required( VERSION 3.14 )
set( CMAKE_CXX_STANDARD 14 )
project( libuuas )

# Libuuas options
option( UUAS_ENABLE_CLANG_TIDY "" ON )

# Set compile flags
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Find clang-tidy executable
find_program( CLANG_TIDY_EXE NAMES "clang-tidy" )
if( NOT CLANG_TIDY_EXE )
  message( STATUS "clang-tidy not found." )
else()
  message( STATUS "clang-tidy found: ${CLANG_TIDY_EXE}" )
  set( DO_CLANG_TIDY "${CLANG_TIDY_EXE}" "-checks=*,-fuchsia-default-arguments,-fuchsia-default-arguments-calls,-modernize-use-trailing-return-type,-*-vararg" )
endif()

# Catch2 dependency
include(FetchContent)
FetchContent_Declare( catch2cmake URL https://github.com/catchorg/Catch2/archive/v2.13.0.tar.gz )
FetchContent_GetProperties( catch2cmake )
if ( NOT catch2cmake_POPULATED )
  FetchContent_Populate( catch2cmake )
endif()
option( CATCH_BUILD_TESTING "" OFF )
option( CATCH_INSTALL_DOCS "" OFF )
add_subdirectory( ${catch2cmake_SOURCE_DIR} ${catch2cmake_BINARY_DIR} )

# Geos dependency
include(FetchContent)
FetchContent_Declare( geoscmake URL https://github.com/libgeos/geos/archive/3.6.4.tar.gz )
FetchContent_GetProperties( geoscmake )
if ( NOT geoscmake_POPULATED )
  FetchContent_Populate( geoscmake )
endif()
option( GEOS_ENABLE_TESTS "" OFF )
add_subdirectory( ${geoscmake_SOURCE_DIR} ${geoscmake_BINARY_DIR} )

# Libexiv2 dependency
include(FetchContent)
FetchContent_Declare( exiv2cmake URL https://www.exiv2.org/releases/exiv2-0.27.3-Source.tar.gz )
FetchContent_GetProperties( exiv2cmake )
if ( NOT exiv2cmake_POPULATED )
  FetchContent_Populate( exiv2cmake )
endif()
option( EXIV2_BUILD_SAMPLES "" OFF )
option( EXIV2_BUILD_EXIV2_COMMAND "" OFF )
add_subdirectory( ${exiv2cmake_SOURCE_DIR} ${exiv2cmake_BINARY_DIR} )

# Protobuf dependency
include(FetchContent)
FetchContent_Declare( protobufcmake URL https://github.com/protocolbuffers/protobuf/releases/download/v3.12.0/protobuf-cpp-3.12.0.tar.gz )
FetchContent_GetProperties( protobufcmake )
if ( NOT protobufcmake_POPULATED )
  FetchContent_Populate( protobufcmake )
endif()
option( protobuf_BUILD_TESTS "" OFF )
option( protobuf_BUILD_PROTOC_BINARIES "" OFF )
add_subdirectory( ${protobufcmake_SOURCE_DIR}/cmake ${protobufcmake_BINARY_DIR} )

# Libuuas protobuf dependency
add_library( uuas_pb STATIC ${CMAKE_SOURCE_DIR}/src/libuuas/uuaspb.pb.cc )
target_link_libraries( uuas_pb PUBLIC protobuf::libprotobuf )
target_compile_options( uuas_pb PUBLIC "-fPIC" )

# Main libuuas so
add_library( uuas SHARED
  ${CMAKE_SOURCE_DIR}/src/libuuas/uuas.cpp
  ${CMAKE_SOURCE_DIR}/src/libuuas/waypoint.cpp
  ${CMAKE_SOURCE_DIR}/src/libuuas/utm.cpp
)
target_include_directories( uuas PUBLIC ${CMAKE_SOURCE_DIR}/include/ ${CMAKE_SOURCE_DIR}/src/ )
target_include_directories( uuas SYSTEM PUBLIC ${geoscmake_SOURCE_DIR}/include/ ${geoscmake_BINARY_DIR}/include/ )
target_link_libraries( uuas PUBLIC uuas_pb exiv2lib geos_c )
target_compile_options( uuas PUBLIC "-Wall" "-Wextra" )

# Libuuas tests
add_executable( uuastest
  ${CMAKE_SOURCE_DIR}/test/test_main.cpp
  ${CMAKE_SOURCE_DIR}/test/test_waypoint.cpp
  ${CMAKE_SOURCE_DIR}/test/test_utm.cpp
  ${CMAKE_SOURCE_DIR}/test/test_utils.cpp
)
target_include_directories( uuas SYSTEM PUBLIC ${catch2cmake_SOURCE_DIR}/single_include/ )
target_link_libraries( uuastest PUBLIC uuas Catch2::Catch2 )
enable_testing()
add_test( NAME uuastest COMMAND uuastest )

# Use clang-tidy as a sanity checker for libuuas
if ( UUAS_ENABLE_CLANG_TIDY AND CLANG_TIDY_EXE )
  message( STATUS "Will run clang-tidy check." )
  set_target_properties( uuas PROPERTIES CXX_CLANG_TIDY "${DO_CLANG_TIDY}" )
endif()

# Install directives
include(GNUInstallDirs)
install(
  TARGETS uuas
  EXPORT uuas
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(
  TARGETS uuas_pb
  EXPORT uuas_pb
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install (
  DIRECTORY ${CMAKE_SOURCE_DIR}/include/
  DIRECTORY ${CMAKE_SOURCE_DIR}/src/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING PATTERN "*.h*"
)

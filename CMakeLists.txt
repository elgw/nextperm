cmake_minimum_required(VERSION 3.22)

project(nextperm
  LANGUAGES C)

set (CMAKE_C_STANDARD 11)

#
# Default build type is RELEASE
#
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Don't install to /usr/local/ use /usr/
set( CMAKE_INSTALL_PREFIX
  /usr/ )

add_library(nextperm SHARED
  nextperm.c)

set_target_properties(nextperm
  PROPERTIES PUBLIC_HEADER nextperm.h)

include("GNUInstallDirs")

INSTALL(TARGETS nextperm
  PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_FULL_INCLUDEDIR}"
  LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
)

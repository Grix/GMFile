cmake_minimum_required (VERSION 3.7)

option (NFD_WIN 
        "Build nfd for windows api (otherwise gtk)" ON) 

set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_C_FLAGS_RELEASE "/MT")
set(CMAKE_BUILD_TYPE "Release")

add_library(nfd_common nfd/nfd_common.c)

if (NFD_WIN)
	add_library(nfd nfd/nfd_win.cpp)
else (NFD_WIN)
	add_library(nfd nfd/nfd_gtk.c)
endif (NFD_WIN)

target_link_libraries(nfd nfd_common)

add_library(GMFile SHARED GMFile.cpp)

target_link_libraries(GMFile nfd)
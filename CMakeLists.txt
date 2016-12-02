cmake_minimum_required (VERSION 3.5)

set(CMAKE_BUILD_TYPE "Release")

add_library(nfd_common nfd/nfd_common.c)

if (MSVC)
	set(CMAKE_CXX_FLAGS_RELEASE "/MT")
	set(CMAKE_C_FLAGS_RELEASE "/MT")
	add_library(nfd nfd/nfd_win.cpp)
endif (MSVC)

if (UNIX)
	set(CMAKE_CXX_FLAGS_RELEASE "-fPIC -m32")
	set(CMAKE_C_FLAGS_RELEASE "-fPIC -m32")
	find_package(PkgConfig REQUIRED)
	pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
	include_directories(${GTK3_INCLUDE_DIRS})
	link_directories(${GTK3_LIBRARY_DIRS})
	add_definitions(${GTK3_CFLAGS_OTHER})
	add_library(nfd nfd/nfd_gtk.c)
	target_link_libraries(nfd ${GTK3_LIBRARIES})
endif (UNIX)

target_link_libraries(nfd nfd_common)

add_library(GMFile SHARED GMFile.cpp)

target_link_libraries(GMFile nfd)
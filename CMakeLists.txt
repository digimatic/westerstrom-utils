cmake_minimum_required(VERSION 3.17)

if( "${CMAKE_VERSION}" VERSION_GREATER "3.19")
	cmake_policy(SET CMP0114 NEW)
endif()
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED TRUE)
set (CMAKE_XCODE_ATTRIBUTE_COMPILER_INDEX_STORE_ENABLE NO)

Include(FetchContent)
FetchContent_Declare(
		Catch2
		GIT_REPOSITORY https://github.com/catchorg/Catch2.git
		GIT_TAG        v2.13.1)
FetchContent_MakeAvailable(Catch2)

project(westerstrom_utils)

add_library(westerstrom_utils
	include/westerstrom/grid.h
	include/westerstrom/pow_int.h
	include/westerstrom/set_cross.h
	include/westerstrom/tuple_math.h
	src/library.cpp
	src/library.h)

add_subdirectory(test)

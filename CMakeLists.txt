# Copyright 2021 Qiying Wang. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

cmake_minimum_required(VERSION 3.10)

project(symhash)

# generating build/compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

set(SYMHASH_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

include_directories(${SYMHASH_INCLUDE_DIR})

set(SRCS src/symhash.c)

add_library(symhash SHARED ${SRCS})
add_library(symhash_static STATIC ${SRCS})
# Rename libsymhash_statis.a to libsymhash.a
set_target_properties(symhash_static PROPERTIES OUTPUT_NAME "symhash")
# Associate header files
set_target_properties(symhash PROPERTIES PUBLIC_HEADER ${SYMHASH_INCLUDE_DIR}/symhash.h)
set_target_properties(symhash_static PROPERTIES PUBLIC_HEADER ${SYMHASH_INCLUDE_DIR}/symhash.h)

# Shared library needs a version number.
# VERSION: library version
# SOVERSION: API version
set_target_properties(symhash PROPERTIES VERSION 1.0 SOVERSION 1)

# make install
install(TARGETS symhash symhash_static
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# using the following command to install gtest library
# apt install libgtest-dev
enable_testing()
add_subdirectory(test)

# using the following command to install benchmark library
# apt install libbenchmark-dev
add_subdirectory(bench)

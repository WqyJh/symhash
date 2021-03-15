# Copyright 2021 Qiying Wang. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

# using the following command to install benchmark library
# apt install libbenchmark-dev
find_package(benchmark REQUIRED)

add_executable(symhash_bench
    symhash_bench.cc)

target_link_libraries(symhash_bench
    benchmark::benchmark
    symhash
)

add_custom_target(bench
    COMMAND ./symhash_bench
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} # build/bench/
)

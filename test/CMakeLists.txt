# Copyright 2021 Qiying Wang. All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.

# using the following command to install gtest library
# apt install libgtest-dev
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(GTEST_LIBS ${GTEST_BOTH_LIBRARIES} pthread)

add_executable(symhash_test symhash_test.cc)

target_link_libraries(symhash_test
    ${GTEST_LIBS}
    symhash)

gtest_discover_tests(symhash_test)

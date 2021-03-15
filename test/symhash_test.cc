// Copyright 2021 Qiying Wang. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <gtest/gtest.h>

#include <symhash.h>

TEST(symhash_test, Symmetric) {
    symhash_init();

    uint32_t sip = inet_addr("192.168.1.1");
    uint32_t dip = inet_addr("192.168.2.1");
    uint16_t sport = htons(10000);
    uint16_t dport = htons(22);
    uint32_t ret1 = symhash(sip, dip, sport, dport);
    uint32_t ret2 = symhash(dip, sip, dport, sport);
    EXPECT_EQ(ret1, ret2);
}

TEST(symhash_test, NotEqual) {
    symhash_init();

    uint32_t sip = inet_addr("192.168.1.1");
    uint32_t dip = inet_addr("192.168.2.1");
    uint16_t sport = htons(10000);
    uint16_t dport = htons(22);
    uint16_t dport2 = htons(33);
    uint32_t ret1 = symhash(sip, dip, sport, dport);
    uint32_t ret2 = symhash(dip, sip, sport, dport2);
    EXPECT_NE(ret1, ret2);
}

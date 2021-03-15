// Copyright 2021 Qiying Wang. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.


#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <benchmark/benchmark.h>

#include <symhash.h>

static void BM_symhash(benchmark::State& state) {
    symhash_init();

    uint32_t sip = inet_addr("192.168.1.1");
    uint32_t dip = inet_addr("192.168.2.1");
    uint16_t sport = htons(10000);
    uint16_t dport = htons(22);
    
    for (auto _ : state)
        symhash(sip, dip, sport, dport);
}

BENCHMARK(BM_symhash);

BENCHMARK_MAIN();

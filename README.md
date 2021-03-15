# libsymhash

## Usage

```c
#include <symhash.h>

// initialize before use it
symhash_init();

// compute hash
uint32_t hash = symhash(sip, dip, sport, dport);

// compute the ports to forward
nb_ports = 8;
target_port = hash % nb_ports;
```

## Build

```bash
mkdir build/
cd build/
cmake ..
make
sudo make install
```

## Test

```bash
make test
```

Got output like this.

```bash
Running tests...
Test project /home/wqy/symhash/build
    Start 1: symhash_test.Symmetric
1/2 Test #1: symhash_test.Symmetric ...........   Passed    0.00 sec
    Start 2: symhash_test.NotEqual
2/2 Test #2: symhash_test.NotEqual ............   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.00 sec
```

## Benchmark

```bash
make bench
```

Got output like this

```bash
2021-03-15 21:58:04
Running ./symhash_bench
Run on (12 X 4300 MHz CPU s)
CPU Caches:
  L1 Data 32K (x6)
  L1 Instruction 32K (x6)
  L2 Unified 256K (x6)
  L3 Unified 12288K (x1)
Load Average: 2.53, 2.17, 2.09
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_symhash       10.2 ns         10.2 ns     65843546
```

```bash
2021-03-15 21:12:34
Running ./bench/symhash_bench
Run on (12 X 4300 MHz CPU s)
CPU Caches:
  L1 Data 32K (x6)
  L1 Instruction 32K (x6)
  L2 Unified 256K (x6)
  L3 Unified 12288K (x1)
Load Average: 2.00, 2.11, 2.11
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_symhash       10.8 ns         10.8 ns     67108302
```

## Regards

Currently the main algorithm comes from [netmap/lb](https://github.com/luigirizzo/netmap/blob/master/apps/lb/pkt_hash.c).

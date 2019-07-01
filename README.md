# Performance

See https://willrosecrans.wordpress.com/2019/07/01/the-underappreciated-scaling-of-memory-access-costs-hidden-by-the-cult-of-big-o/ for a blog post related to this repo.

A small test application that demonstrates that O(1) complexity doesn't always mean O(1) runtime for an operation.  The cost of data access routinely has scaling factors that relate to the working set size even in scenarios where the nominal operation count is constant.  The exact reasoning is mainly "cache hierarchies" but issues of locality of reference also include a bunch of stuff like locality of reference being important within the DRAM chips themselves as consecutive rows and pages of the DRAM are accessed quickly, but nonconsecutive accesses are slow.  Picking apart the exact differences between slowness contributions of the various parts of the memory hierarchy would probably require a rather more complex test program.


# Build and Run

A CMake script is provided.  It should be possible to open it in most IDE's, or do the usual CMake

`mkdir build && cd build && cmake .. && cmake --build .`

Tested on Ubuntu 18.04 with g++-7, but should work anywhere with a modern C++ compiler and recent CMake.

# Example Output


| Index | Element Count | Time taken per operation | Final value |
|-------|---------------|--------------------------|-------------|
| 0 | 1 | 6.00329 | 0 |
| 1 | 2 | 5.66687 | 0 |
| 2 | 4 | 5.73156 | 0 |
| 3 | 8 | 5.66453 | 0 |
| 4 | 16 | 6.40685 | 0 |
| 5 | 32 | 5.68036 | 0 |
| 6 | 64 | 5.59909 | 0 |
| 7 | 128 | 5.69097 | 19 |
| 8 | 256 | 6.11891 | 0 |
| 9 | 512 | 5.69572 | 0 |
| 10 | 1024 | 5.85073 | 140 |
| 11 | 2048 | 6.02329 | 1916 |
| 12 | 4096 | 5.76805 | 2482 |
| 13 | 8192 | 6.82305 | 446 |
| 14 | 16384 | 7.47072 | 11219 |
| 15 | 32768 | 7.9075 | 8015 |
| 16 | 65536 | 11.3467 | 3473 |
| 17 | 131072 | 12.9268 | 22863 |
| 18 | 262144 | 13.7839 | 186011 |
| 19 | 524288 | 23.5884 | 510764 |
| 20 | 1048576 | 54.1339 | 272145 |
| 21 | 2097152 | 70.9539 | 43105 |
| 22 | 4194304 | 76.356 | 1971869 |
| 23 | 8388608 | 81.2458 | 7904547 |
| 24 | 16777216 | 85.8774 | 507276 |
| 25 | 33554432 | 88.6081 | 11616904 |
| 26 | 67108864 | 93.1648 | 50784487 |




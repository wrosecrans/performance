#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>

using std::vector;
using std::shuffle;
using std::default_random_engine;
using std::chrono::system_clock;
using std::cout;


auto now_count() {
    return system_clock::now().time_since_epoch().count();
}

int main() {
    auto max_idx = 28;  // Arbitrary limit, but allocating many GB in one go will probably fail.
    auto seed = 4;      // True random per method in standard xkcd-221
    auto iterations = 1000*1000;  // Arbitrary, but large enough to get useful data.

    cout << "Index, Element Count, Time taken per operation, Final value\n";


    for (int i=0; i<max_idx; i++) {

        unsigned long size = 1 << i;    // Doubling in each step gives sufficiently granular data to be interesting
                                        // Feel free to run billions of iterations for every size if you are bored.
        vector<unsigned long> pool;
        pool.reserve(size);
        // Demonstrating the cost of repeated memory allocations by not
        // reserving in advance is left for a different example program.

        cout << i << ", " << size << ", ";
        for(unsigned long j=0; j<size; j++) {
            pool.push_back(j);
        }

        // Shuffle so every element of the vector has a random valid index
        // Not perfect, and not pessimal, but roughly approximates real-world
        // behavior of arbitrary, unpredictable reads.
        shuffle(pool.begin(), pool.end(), default_random_engine(seed));


        unsigned long last = 0;
        auto start = now_count();
        for (unsigned long j = 0; j < iterations; ++j) {
            // Get a value.  In theory, this is an O(1) operation.
            last = pool[last];
        }
        auto end = now_count();
        auto time_taken = end - start;

        // Print out the value of "last" so that it doesn't just
        // get optimized out as an unused value when compiling with optimizations.
        // Works intuitively with compilers that don't support "nodiscard" when
        // doing simple demo benchmarks like this that don't really use a result.

        cout << float(time_taken) / iterations << ", " << last << std::endl;
    }
    return 0;
}

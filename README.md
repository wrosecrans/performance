# Performance

See https://willrosecrans.wordpress.com/2019/07/01/the-underappreciated-scaling-of-memory-access-costs-hidden-by-the-cult-of-big-o/ for a blog post related to this repo.

A small test application that demonstrates that O(1) complexity doesn't always mean O(1) runtime for an operation.  The cost of data access routinely has scaling factors that relate to the working set size even in scenarios where the nominal operation count is constant.  The exact reasoning is mainly "cache hierarchies" but issues of locality of reference also include a bunch of stuff like locality of reference being important within the DRAM chips themselves as consecutive rows and pages of the DRAM are accessed quickly, but nonconsecutive accesses are slow.  Picking apart the exact differences between slowness contributions of the various parts of the memory hierarchy would probably require a rather more complex test program.







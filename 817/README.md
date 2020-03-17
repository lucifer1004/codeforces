# Educational Codeforces Round 23

- [x] A
- [x] B
- [x] C
- [x] D
- [ ] E
- [ ] F

## Problem D - Imbalanced Array

This is a typical monotonic stack problem.

The key point is that when calculating $left_lo$ and $right_lo$, we should use $<$ for one side, and $\leq$ for the other side. In this way, there will be no overlapping or omission.
# Codeforces Round 626 Div.1

- [x] A
- [x] B:bookmark_tabs:
- [x] C:bookmark_tabs:
- [ ] D
- [ ] E
- [ ] F

## Problem B - Present

We check for each bit of the final answer whether it is set of not.

For the k-th bit, we take all numbers modulo $2^{k+1}$, then sort the new array, and query for number of pairs whose sum is within $[2^k, 2^{k+1})$ or $[3\cdot2^k, 2^{k+2})$. If the number is odd, then the k-th bit of the final answer is set.

## Problem C - Instant Noodles

The observation is that we can divide vertices on the right into several groups, such that the vertices in the same group have the same edge pattern. Here we need to use some hashing technique to represent this pattern.
# Educational Codeforces Round 83

- [x] A
- [x] B
- [x] C
- [x] D
- [x] E:bookmark_tabs:
- [ ] F
- [ ] G

## Problem E - Array Shrinking

If we have precalculated whether $[l, r]$ can be shrinked into one number, then we can do a simple $O(n^2)$ DP to get the answer.

How to calculate $f[l][r]$? We can use an $O(n^3)$ DP, starting from $f[i][i]=i$. 
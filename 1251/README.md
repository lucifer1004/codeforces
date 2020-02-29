# Educational Codeforces Round 75

- [x] A
- [x] B
- [x] C
- [x] D
- [x] E1:bookmark_tabs:
- [x] E2:bookmark_tabs:
- [ ] F

## Problem E - Voting

1. Group the voters by $m_i$. 
2. Instead of starting from the lowest, we start from the voters who require the highest number of other voters. We add them into the candidate pool (which is indeed a min-heap of price). If there are enough voters (voters in lower groups + currently paid voters), we just skip this group. Otherwise, we need to buy the exact number of voters we need from the candidate pool.
3. In order to save time, $prev[i]$ is pre-calculated.

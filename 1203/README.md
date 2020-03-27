# Codeforces Round 579 Div.3

- [x] A
- [x] B
- [x] C
- [x] D1
- [x] D2
- [x] E
- [x] F1
- [x] F2:bookmark_tabs:

## Problem F - Complete the Projects

The key point is to sort projects with negative rating changes in descending order of $require[i]+delta[i]$, so that when we do knapsack dp, it is ensured that the best sequence is chosen.
# Technocup 2020 - Elimination Round 1

- [x] A
- [x] B
- [x] C
- [x] D
- [x] E:bookmark_tabs:
- [ ] F
- [ ] G

## Problem E - Paint the Tree

For each node, there are two cases. We can either choose its back edge (the edge leading to its parent), or not. When we choose its back edge, we can choose at most $k-1$ from all its children. When we do not choose the back edge, we can choose at most $k$ children. The net value of choosing an edge (u,v) thus becomes $f[v] + w - g[v]$, where $f[v]$ is the best value when we can choose $k-1$ children of $v$, and $g[v]$ is the best value when we can choose $k$ children of $v$.

This observation leads to a natural DP solution. For each node $u$, we keep a max-heap of $f[v] + w - g[v]$. We will then choose the largest $k$ positive values to calculate $g[u]$, and the largest $k-1$ positive values to calculate $f[u]$.
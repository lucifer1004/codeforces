# Codeforces Round 639 Div.1

- [x] A
- [x] B
- [x] C:bookmark_tabs:
- [ ] D
- [ ] E
- [ ] F

## Problem C - Quantifier Question

It is obvious that we need to do topological sort to check the validity of the inequalities.

The problem is where we should put the universal quantifiers. If an index has no comparable indices to its left, it can be made universal. But is this strategy optimal?

We can see that, if $a_i$ and $a_j$ ($i < j$) is comparable, and we make $j$ universal instead of $i$, more indices will be affected and cannot be made universal.

How do we find the minimal index which is comparable to a certain index? We can just propagate the minimal value during topological sort. Since all valid inequalities can construct a DAG, this simple method works.
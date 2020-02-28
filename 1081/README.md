# Avito Cool Challenge 2018

- [x] A
- [x] B
- [x] C
- [x] D:bookmark_tabs:
- [x] E
- [x] F:bookmark_tabs:
- [ ] G
- [ ] H

## Problem D - Maximum Distance

The biggest challenge is to identify this as an MST problem. The special definition of shortest path ensures that the shortest distance between any nodes equals to the distance between them in any MST of the graph.

Another observation is that only if there are special nodes in both sides of en edge can it contribute to the answer.

Based on the observation, we can find that the final answer for all nodes should be the same. Why? Suppose the edge with highest weight that connects at least two special nodes is e, and connects two special nodes u and v. Since the MST is a tree, for all other special nodes, they need either to go to u via v, or go to v via u. So the answer for those nodes will also be the weight of the edge e.

Since we need to identify whether a component contains special nodes, it is natural to use Kruskal algorithm based on DSU. When merging two components, we check if they both contain special nodes. If so, since in Kruskal the edges are sorted in a non-decreasing order, we can safely update the answer with the newly added edge.
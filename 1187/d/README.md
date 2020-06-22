# Notes

## Segment Tree

We store the indices in $a$ of each number in the increasing order in $n$ stacks $s[1..n]$.

When processing $b_i$, we use the top element of $s[b[i]]$, however, we must ensure that there is no number less than $b[i]$ that occurs before this element. So we use a segment tree to maintain the minimum of segments.

## Fenwick Tree

Generally, Fenwick trees cannot be used in RMQ problems, however, there is a special case if there is only single element addition (elements will not decrease) and we care about range maximum of segments [1..k].

Instead of storing the indices of $a$, we now store the indices of $b$ in $s[1..n]$. Then we process $a$ from the end to the beginning. We greedily choose the last index of $s[a[i]]$ and assign it to $p[i]$.

Then we need to validate $p$ from the beginning to the end. For each element $a[i]$, we need to check if we have placed a number less than it to the right of $p[i]$ (because a less number to the left of current number cannot go to its right through valid moves). This can be done via the specific-designed Fenwick tree, by querying the maximum of range $[1..a[i]-1]$.

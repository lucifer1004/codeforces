# Codeforces Round 654 Div.2

- [x] A
- [x] B
- [x] C
- [x] D
- [x] E1
- [x] E2
- [x] F

## Problem E2 - Asterism (Hard Version)

The number of permutations for a given $x$ can be written in:

$$f(x)=\Pi_{i=0}^{n-1} ((\sum_{j=0}^{n-1}a_j\leq x+i)-i)$$

Since $p$ is a prime number, in order that $f(x)$ cannot be divided by $p$, we must ensure that $(\sum_{j=0}^{n-1}a_j\leq x+i)-i<p$ holds for every $i$. And in order that there is a possible permutation, we must ensure that $(\sum_{j=0}^{n-1}a_j\leq x+i)-i\geq1$ holds for every $i$.

Proof: Let's denote $(\sum_{j=0}^{n-1}a_j\leq x+i)-i$ as $g(i)$. We can find that, since $\sum_{j=0}^{n-1}a_j\leq x+i$ never decreases, so if $g(i)$ decreases, it can decrease at most $1$. Another observation is that $g(n-1)=1$. So if there is $i_1$ such that $g(i_1)>p$, there must be $i_2>i_1$ which satisfies $g(i_2)=p$, which makes $f(x)$ divided by $p$.

So the problem is now: how many $x$ are there that satisfy

$$\forall i, 1\leq g(i)<p$$

Since $g(i)$ increases with x, the answer must be a continuous segment $[lo..hi]$.

Now we sort the array $a$ in the ascending order.

For $lo$, we have

$$\forall i, lo+i\geq a_i\implies lo\leq\max(a_i-i)$$

For $hi$, we have

$$\forall i, hi+i<a_{i+p-1}\implies hi<\min(a_{i+p-1}-i)$$

So the final answer is the segment

$$[\max(a_i-i)..\min(a_{i+p-1}-i)-1]$$

## Problem F - Raging Thunder

### Helping information

Obviously, this is a segment-tree problem. Then what do we need to maintain in each node?

In my implementation, the following information is maintained:

- $ll$, the length of the prefix "<<<"
- $lr$, the length of the prefix ">>>"
- $rl$, the length of the suffix "<<<"
- $rr$, the length of the suffix ">>>"
- $lhi$, the length of the prefix ">>><<<" (at least 1 "<" and 1 ">")
- $rhi$, the length of the suffix ">>><<<" (at least 1 "<" and 1 ">")
- $hi$, the length of the longest ">>><<<" (at least 1 "<" and 1 ">")
- $nlhi$, the length of the prefix "<<<>>>" (at least 1 "<" and 1 ">")
- $nrhi$, the length of the suffix "<<<>>>" (at least 1 "<" and 1 ">")
- $nhi$, the length of the longest "<<<>>>" (at least 1 "<" and 1 ">")
- $mark$, whether the children of the current node should be flipped. It is also used as the flag for lazy propagation.

Then the answer to the query within a node becomes $\max(hi, ll, rr)$.

With such information, node combination and node flipping becomes easier and clearer.

### Node flipping

- Flip $mark$.
- Swap $ll$ and $lr$, $rl$ and $rr$.
- Swap $lhi$ and $nlhi$, $rhi$ and $nrhi$, $hi$ and $nhi$.

### Node combination

- New $ll$ is $l.ll$ if $l.ll < l.len$, otherwise $l.ll + r.ll$. It is similar for $lr$, $rl$ and $rr$.
- New $lhi$:
  - If $0<l.lhi<l.len$, just use $l.lhi$
  - If $l.lhi=l.len$, use $l.lhi+r.ll$
  - If $l.lhi=0$ and $l.lr=l.len$ and $\max(r.lhi, r.ll) > 0$, use $l.lr+\max(r.lhi, r.ll)$
  - It is similar for $rhi$, $nlhi$ and $nrhi$
- New $hi$ is the maximum of the following:
  - $\max(lhi, rhi)$
  - $\max(l.rhi+r.ll(\mathrm{if}\ l.rhi > 0), l.rr+r.ll(\mathrm{if}\ l.rr > 0, r.ll > 0), l.rr+r.lhi(\mathrm{if}\ r.lhi > 0))$
  - $\max(l.hi, r.hi)$
- New $nhi$ can be calculated similarly.

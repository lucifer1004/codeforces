# Codeforces Round 586 Div.1+2

- [x] A
- [x] B
- [x] C
- [x] D:bookmark_tabs:
- [ ] E
- [ ] F
- [ ] G

## Problem D - Alex and Julian

Note that the vertices are all integers, instead of the integers in B. So the final goal is that all integers can be divided into two groups.

We divide B into several groups based on the lowest bit, then we choose the largest group.

Supposing that we choose group $2^k$, then the numbers in this group can be represented as $(2i-1)\cdot2^k$. For two arbitrary integers $a$ and $b$, if there is en edge between $a$ and $b$, then

$$|a-b|=(2i-1)\cdot2^k$$

which means that $\left\lfloor\frac{a}{2^k}\right\rfloor$ and $\left\lfloor\frac{b}{2^i}\right\rfloor$ have different parities. So we can conclude that all integers can be divided into two groups based on the $2^k$-parity.
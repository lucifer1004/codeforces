from sys import stdin
from math import gcd
def input(): return stdin.readline().strip()


def lcm(a, b): return a * b // gcd(a, b)


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    s = input()
    p = [xi - 1 for xi in read_ints()]
    vis = [False] * n
    ans = 1
    for i in range(n):
        if vis[i]:
            continue
        vis[i] = True
        loop = [s[i]]
        while not vis[p[i]]:
            i = p[i]
            vis[i] = True
            loop.append(s[i])
        q = ''.join(loop)
        l = len(q)
        for j in range(1, l):
            if l % j == 0 and q == q[:j] * (l // j):
                l = j
                break
        ans = lcm(ans, l)
    print(ans)

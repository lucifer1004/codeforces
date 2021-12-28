from fractions import *
from sys import stdin
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


MOD = 10 ** 9 + 7


def inv(x):
    return pow(x, MOD - 2, MOD)


t = read_int()
for case_num in range(t):
    n, m, rb, cb, rd, cd, p = read_ints()
    p_clean = p * inv(100) % MOD
    p_idle = (100 - p) * inv(100) % MOD

    s = set()
    dr = 1
    dc = 1
    if not 1 <= rb + dr <= n:
        dr = -dr
    if not 1 <= cb + dc <= m:
        dc = -dc

    LOOP = 0
    MATCHED = 0
    F = 0
    while (rb, cb, dr, dc) not in s:
        s.add((rb, cb, dr, dc))
        if rb == rd or cb == cd:
            F += LOOP * p_clean * pow(p_idle, MATCHED, MOD)
            F %= MOD
            MATCHED += 1

        rb += dr
        cb += dc
        if not 1 <= rb + dr <= n:
            dr = -dr

        if not 1 <= cb + dc <= m:
            dc = -dc

        LOOP += 1

    pm = pow(p_idle, MATCHED, MOD)

    ans = F * inv(MOD + 1 - pm) + LOOP * pm * inv(MOD + 1 - pm)
    ans %= MOD

    print(ans)

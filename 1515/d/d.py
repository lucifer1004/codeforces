from collections import Counter
from sys import stdin


def read_int():
    return int(stdin.readline())


def read_ints():
    return map(int, stdin.readline().split(' '))


t = read_int()
for case_num in range(t):
    n, l, r = read_ints()
    c = list(read_ints())
    lcnt = Counter()
    rcnt = Counter()
    for i in range(n):
        if i < l:
            lcnt[c[i]] += 1
        else:
            rcnt[c[i]] += 1
    for key in lcnt:
        delta = min(lcnt[key], rcnt[key])
        rcnt[key] -= delta
        lcnt[key] -= delta
        l -= delta
        r -= delta

    ans = 0

    for key in lcnt:
        while l > r and lcnt[key] >= 2:
            l -= 2
            lcnt[key] -= 2
            ans += 1

    for key in rcnt:
        while r > l and rcnt[key] >= 2:
            r -= 2
            rcnt[key] -= 2
            ans += 1

    ans += max(l, r)
    print(ans)

from sys import stdin
from collections import defaultdict
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    d = defaultdict(list)
    ans = 0
    for i, num in enumerate(a):
        d[num].append(i)
    for num in d:
        if len(d[num]) >= 2:
            ans = max(ans, n - min(y - x for x,
                      y in zip(d[num][:-1], d[num][1:])))
    print(ans if ans > 0 else -1)

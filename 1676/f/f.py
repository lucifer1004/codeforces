from sys import stdin
from collections import Counter
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    cnt = Counter(read_ints())
    keys = sorted(cnt.keys())
    last = -1
    ans = 0
    l = 0
    r = 0
    acc = 0
    for key in keys:
        if cnt[key] < k:
            acc = 0
        elif key == last + 1:
            acc += 1
        else:
            acc = 1
        if acc > ans:
            ans = acc
            r = key
            l = key - acc + 1
        last = key
    if ans == 0:
        print(-1)
    else:
        print(l, r)

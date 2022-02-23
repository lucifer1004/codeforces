from sys import stdin
from collections import Counter
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n, x = read_ints()
    a = list(read_ints())
    cnt = Counter(a)
    ans = 0
    keys = sorted(cnt.keys())
    for key in keys:
        if cnt[key] == 0:
            continue
        if key * x in cnt:
            pr = min(cnt[key], cnt[key * x])
            cnt[key] -= pr
            cnt[key * x] -= pr
        ans += cnt[key]
    print(ans)

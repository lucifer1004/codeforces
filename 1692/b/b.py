from sys import stdin
from collections import Counter
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    c = Counter(a)
    ans = 0
    for k in c:
        ans += c[k] - 1
    print(n - 2 * ((ans - 1) // 2 + 1))

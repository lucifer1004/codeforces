from sys import stdin
from collections import defaultdict
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n, m = read_ints()
    a = [list(read_ints()) for _ in range(n)]
    diag = defaultdict(int)
    idiag = defaultdict(int)
    for i in range(n):
        for j in range(m):
            diag[i + j] += a[i][j]
            idiag[i - j] += a[i][j]
    ans = max(diag[i + j] + idiag[i - j] - a[i][j]
              for i in range(n) for j in range(m))
    print(ans)

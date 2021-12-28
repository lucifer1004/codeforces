from sys import stdin
from collections import deque
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    ranges = [tuple(read_ints()) for _ in range(n)]
    L = [[] for _ in range(n + 1)]
    R = [[] for _ in range(n + 1)]
    for l, r in ranges:
        L[l].append(r)
        R[r].append(l)
    for i in range(1, n + 1):
        L[i].sort()
        R[i].sort()

    L = [deque(li) for li in L]
    R = [deque(ri) for ri in R]

    ans = []

    def solve(l, r):
        if l > r:
            return

        L[l].pop()
        R[r].popleft()

        if l == r:
            ans.append((l, r, l))
        elif len(L[l]) > 0:
            mid = L[l][-1]
            ans.append((l, r, mid + 1))
            solve(l, mid)
            solve(mid + 2, r)
        elif len(R[r]) > 0:
            mid = R[r][0]
            ans.append((l, r, mid - 1))
            solve(l, mid - 2)
            solve(mid, r)

    solve(1, n)

    for l, r, val in ans:
        print(l, r, val)

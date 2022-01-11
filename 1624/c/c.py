from sys import stdin
from heapq import *
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    pq = list(map(lambda x: -x, read_ints()))
    heapify(pq)
    while len(pq) > 0 and pq[0] <= -len(pq):
        if pq[0] == -len(pq):
            heappop(pq)
            continue

        u = heappop(pq)
        v = (-u) // 2
        heappush(pq, -v)
    print('YES' if len(pq) == len(set(pq)) else 'NO')

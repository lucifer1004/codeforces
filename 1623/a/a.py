from sys import stdin
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n, m, rb, cb, rd, cd = read_ints()
    dr = 1
    dc = 1
    sec = 0
    while rb != rd and cb != cd:
        if 1 <= rb + dr <= n:
            rb += dr
        else:
            dr = -dr
            rb += dr

        if 1 <= cb + dc <= m:
            cb += dc
        else:
            dc = -dc
            cb += dc

        sec += 1
    print(sec)

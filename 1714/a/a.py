from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n, H, M = read_ints()
    MM = H * 60 + M
    ans = 1440
    for i in range(n):
        h, m = read_ints()
        mm = h * 60 + m
        if mm == MM:
            ans = 0
        elif mm > MM:
            ans = min(ans, mm - MM)
        else:
            ans = min(ans, mm + 1440 - MM)
    print(ans // 60, ans % 60)

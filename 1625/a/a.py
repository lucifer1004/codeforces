from sys import stdin
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n, l = read_ints()
    x = list(read_ints())
    ans = 0
    for i in range(l):
        c = len([xi for xi in x if xi & (1 << i) > 0])
        if c > n - c:
            ans ^= 1 << i
    print(ans)

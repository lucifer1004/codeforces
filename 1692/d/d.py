from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


def palin(h, m):
    return str(h).rjust(2, '0') == str(m).rjust(2, '0')[::-1]


t = read_int()
for case_num in range(t):
    a, x = input().split()
    x = int(x)
    h, m = map(int, a.split(':'))
    start = h * 60 + m
    ans = 1 if palin(h, m) else 0
    nxt = (start + x) % 1440
    while nxt != start:
        h, m = nxt // 60, nxt % 60
        if palin(h, m):
            ans += 1
        nxt = (nxt + x) % 1440
    print(ans)

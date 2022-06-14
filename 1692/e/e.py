from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n, s = read_ints()
    a = list(read_ints())
    if sum(a) < s:
        print(-1)
        continue
    ones = [-1] + [i for i in range(n) if a[i] == 1] + [n]
    hi = 0
    for i in range(1, len(ones) - s):
        hi = max(hi, ones[i + s] - ones[i - 1] - 1)
    print(n - hi)

from sys import stdin
from collections import Counter


def read_int():
    return int(stdin.readline())


def read_ints():
    return map(int, stdin.readline().split(' '))


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    a = list(read_ints())
    a.sort()
    ans = sum(a[:n - 2 * k])
    for i in range(n - 2 * k, n - k):
        if a[i] == a[i + k]:
            ans += 1

    print(ans)

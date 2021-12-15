from sys import stdin
from math import gcd
from functools import reduce


def read_int():
    return int(stdin.readline())


def read_ints():
    return map(int, stdin.readline().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    a1 = [a[i] for i in range(0, n, 2)]
    a2 = [a[i] for i in range(1, n, 2)]
    g1 = reduce(gcd, a1, 0)
    g2 = reduce(gcd, a2, 0)
    if all(num % g1 != 0 for num in a2):
        print(g1)
        continue
    elif all(num % g2 != 0 for num in a1):
        print(g2)
        continue
    else:
        print(0)

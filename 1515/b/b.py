from math import floor, sqrt
from sys import stdin


def read_int():
    return int(stdin.readline())


def is_square(x):
    s = int(floor(sqrt(x)))
    return s * s == x


t = read_int()
for case_num in range(t):
    n = read_int()
    print('YES' if (n % 2 == 0 and is_square(n // 2))
          or (n % 4 == 0 and is_square(n // 4)) else 'NO')

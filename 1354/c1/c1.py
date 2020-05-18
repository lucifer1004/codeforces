from math import sin, pi, sqrt, tan


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    angle = pi / n / 2
    r = 1 / tan(angle)
    print('{:.9f}'.format(r))

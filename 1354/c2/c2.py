from math import sin, pi, sqrt, tan


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    angle = pi / n / 2
    r = 0.5 / sin(angle)
    a = 0
    for i in range(1, n // 2 + 1):
        A = 3 * pi / 4 - i * pi / n
        a = max(a, 2 * r * sin(A))
    print('{:.9f}'.format(a))

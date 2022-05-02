from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    start = n % 2
    for i in range(start, n, 2):
        if a[i] > a[i + 1]:
            a[i], a[i + 1] = a[i + 1], a[i]
    if a == sorted(a):
        print('YES')
    else:
        print('NO')

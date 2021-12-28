from sys import stdin
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for _ in range(t):
    l1, l2, l3 = sorted(read_ints())
    if l1 + l2 == l3 or (l1 == l2 and l3 % 2 == 0) or (l2 == l3 and l1 % 2 == 0):
        print('YES')
    else:
        print('NO')

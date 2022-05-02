from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    x, y = read_ints()
    if y % x == 0:
        print(1, y // x)
    else:
        print(0, 0)

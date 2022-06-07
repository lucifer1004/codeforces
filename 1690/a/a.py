from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    if n % 3 == 0:
        print(n // 3, n // 3 + 1, n // 3 - 1)
    elif n % 3 == 1:
        print(n // 3, n // 3 + 2, n // 3 - 1)
    else:
        print(n // 3 + 1, n // 3 + 2, n // 3 - 1)

from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    m = read_int()
    k = len(str(m))
    print(m - 10 ** (k - 1))

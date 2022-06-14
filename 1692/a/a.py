from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    a = list(read_ints())
    print(len([ai for ai in a[1:] if ai > a[0]]))

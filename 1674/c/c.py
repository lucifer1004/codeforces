from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    s = input()
    p = input()
    n = len(s)
    if p == 'a':
        print(1)
    elif 'a' in p:
        print(-1)
    else:
        print(1 << n)

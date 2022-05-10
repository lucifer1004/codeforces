from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    s = input()
    l = sum(map(int, s[:3]))
    r = sum(map(int, s[3:]))
    print('YES' if l == r else 'NO')

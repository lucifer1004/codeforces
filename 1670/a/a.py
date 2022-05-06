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
    neg = len([x for x in a if x < 0])
    for i in range(n):
        if i < neg:
            a[i] = -abs(a[i])
        else:
            a[i] = abs(a[i])
    print('YES' if a == sorted(a) else 'NO')

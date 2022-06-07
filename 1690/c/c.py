from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    s = list(read_ints())
    f = list(read_ints())
    d = []
    for i in range(n):
        if i == 0 or s[i] >= f[i - 1]:
            d.append(f[i] - s[i])
        else:
            d.append(f[i] - f[i - 1])
    print(' '.join(map(str, d)))

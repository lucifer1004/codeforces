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
    b = list(read_ints())
    delta = [ai - bi for ai, bi in zip(a, b)]
    hi = max(delta)
    valid = hi >= 0 and all(di == hi or (di < hi and bi == 0)
                            for di, bi in zip(delta, b))
    print('YES' if valid else 'NO')

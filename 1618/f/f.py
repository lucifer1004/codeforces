from sys import stdin
from collections import deque


def read_int():
    return int(stdin.readline())


def read_ints():
    return map(int, stdin.readline().split(' '))


def possible(x, y):
    bx = bin(x)[2:].strip('0')
    by = bin(y)[2:].strip('0')
    return bx in by or bx[::-1] in by


def trans(x):
    return int(bin(x)[2:][::-1].lstrip('0'), base=2)


x, y = read_ints()
if not possible(x, y):
    print('NO')
else:
    dq = deque()
    dq.append(x)
    vis = set([x])
    while len(dq) > 0:
        u = dq.popleft()
        if u == y:
            print('YES')
            exit(0)
        for v in range(u * 2, u * 2 + 2):
            vv = trans(v)
            if possible(vv, y) and vv not in vis:
                dq.append(vv)
                vis.add(vv)
    print('NO')

from collections import deque
from sys import stdin


def read_int():
    return int(stdin.readline())


def read_ints():
    return map(int, stdin.readline().split(' '))


t = read_int()
for case_num in range(t):
    n, x = read_ints()
    w = list(read_ints())
    w.sort(reverse=True)
    dq = deque(w)
    ans = []
    acc = 0
    while dq:
        if acc + dq[0] != x:
            acc += dq[0]
            ans.append(dq.popleft())
        elif acc + dq[-1] != x:
            acc += dq[-1]
            ans.append(dq.pop())
        else:
            print('NO')
            break
    if len(ans) == n:
        print('YES')
        print(' '.join(map(str, ans)))

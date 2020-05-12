from collections import deque


def read_int():
    return int(input())


t = read_int()
for case_num in range(t):
    n = read_int()
    if n <= 3:
        print(-1)
    else:
        q = deque([3, 1, 4, 2])
        for i in range(5, n + 1):
            if i % 2 == 1:
                q.append(i)
            else:
                q.appendleft(i)
        print(' '.join(map(str, list(q))))

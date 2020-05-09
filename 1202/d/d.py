from collections import deque


def read_int():
    return int(input())


t = read_int()
for case_num in range(t):
    n = read_int()
    a = 1
    i = 1
    q = deque()
    while n >= a:
        n -= a
        if a > 1:
            q.appendleft('13')
            while a >= 50000 and n >= a:
                n -= a
                q.appendleft('1')
        i += 1
        a += i

    ans = ''.join(list(q)) + '1' * (n + 1) + '337'
    print(ans)

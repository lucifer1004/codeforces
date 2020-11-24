import sys


def read_int():
    return int(sys.stdin.readline())


def read_ints():
    return map(int, sys.stdin.readline().split(' '))


t = read_int()
ans = []
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    seg = [0] * (n + 1)
    curr = 0
    cnt = 0
    for ai in a:
        if ai == curr:
            cnt += 1
        else:
            if cnt > 0:
                seg[curr] += 1
            curr = ai
            cnt = 1
    if cnt > 0:
        seg[curr] += 1
    res = n
    for i in range(1, n + 1):
        if seg[i] == 0:
            continue
        op = seg[i] + 1
        if i == a[0]:
            op -= 1
        if i == a[-1]:
            op -= 1
        res = min(res, op)
    ans.append(str(res))
print('\n'.join(ans))

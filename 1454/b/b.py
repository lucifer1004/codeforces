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
    cnt = [[] for _ in range(n + 1)]
    for i, ai in enumerate(a):
        cnt[ai].append(i + 1)
    found = False
    for i in range(1, n + 1):
        if len(cnt[i]) == 1:
            found = True
            ans.append(str(cnt[i][0]))
            break
    if not found:
        ans.append('-1')
print('\n'.join(ans))

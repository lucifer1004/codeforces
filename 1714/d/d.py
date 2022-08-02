from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


q = read_int()
for case_num in range(q):
    t = input()
    m = len(t)
    n = read_int()
    s = [input() for _ in range(n)]
    ls = list(map(len, s))
    pre = [(-1, -1)] * (m + 1)
    dp = [m + 1] * (m + 1)
    dp[0] = 0
    for i in range(m):
        for j, sj in enumerate(s):
            if ls[j] > i + 1:
                continue
            if sj == t[i-ls[j]+1:i + 1]:
                for k in range(i - ls[j] + 1, i + 1):
                    if dp[i + 1] > dp[k] + 1:
                        dp[i + 1] = dp[k] + 1
                        pre[i + 1] = (k, j)
    if pre[m] == (-1, -1):
        print(-1)
    else:
        ops = []
        p = m
        while p != 0:
            last, j = pre[p]
            ops.append((j + 1, p - ls[j] + 1))
            p = last
        print(len(ops))
        for j, start in ops[::-1]:
            print(j, start)

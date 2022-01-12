from sys import stdin
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


n, l, k = read_ints()
d = list(read_ints()) + [l]
a = list(read_ints())

inf = int(1e10)
dp = [[inf] * (k + 1) for _ in range(n + 1)]
dp[0][0] = 0
for i in range(0, n):
    ndp = [[inf] * (k + 1) for _ in range(n + 1)]
    for j in range(0, i + 1):
        for p in range(k + 1):
            if dp[j][p] == inf:
                continue

            time = dp[j][p] + a[j] * (d[i + 1] - d[i])

            if p < k:
                ndp[j][p + 1] = min(ndp[j][p + 1], time)

            ndp[i + 1][p] = min(ndp[i + 1][p], time)
    dp = ndp

print(min(min(row) for row in dp))

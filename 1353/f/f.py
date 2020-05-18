def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, m = read_ints()
    a = []
    for i in range(n):
        a.append(list(read_ints()))
    for i in range(n):
        for j in range(m):
            a[i][j] -= i + j
    INF = int(1e18)
    ans = INF
    for i in range(n):
        for j in range(m):
            lo = a[i][j]
            can = [[False for j in range(m)] for i in range(n)]
            dp = [[INF for j in range(m)] for i in range(n)]
            can[0][0] = a[0][0] >= lo
            dp[0][0] = a[0][0]
            for p in range(n):
                for q in range(m):
                    if p == 0 and q == 0:
                        continue
                    if a[p][q] < lo:
                        continue
                    if p > 0:
                        can[p][q] = can[p - 1][q]
                        dp[p][q] = dp[p - 1][q]
                    if q > 0:
                        can[p][q] = can[p][q] or can[p][q - 1]
                        dp[p][q] = min(dp[p][q], dp[p][q - 1])
                    dp[p][q] += a[p][q]
            if can[n - 1][m - 1]:
                ans = min(ans, dp[n - 1][m - 1] - lo * (n + m - 1))
    print(ans)

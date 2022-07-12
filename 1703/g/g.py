from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


inf = int(1e18)
t = read_int()
for case_num in range(t):
    n, c = read_ints()
    a = list(read_ints())
    dp = [-inf] * 31
    dp[0] = 0
    ans = 0
    for i in range(n):
        ndp = [-inf] * 31
        for k in range(31):
            # Use good key
            ndp[k] = max(ndp[k], dp[k] + (a[i] >> k) - c)
            # Use bad key
            if k < 30:
                ndp[k + 1] = max(ndp[k + 1], dp[k] + (a[i] >> (k + 1)))
        dp = ndp
        ans = max(ans, max(dp))
    print(ans)

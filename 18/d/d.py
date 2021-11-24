import sys

input = sys.stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


days = read_int()

dp = [0] * (days + 1)
last = dict()

for i in range(1, days + 1):
    dp[i] = dp[i - 1]
    op, val = input().split()
    val = int(val)
    if op == 'sell':
        if val not in last:
            continue
        dp[i] = max(dp[i], dp[last[val]] + (1 << val))
    else:
        last[val] = i

print(dp[-1])

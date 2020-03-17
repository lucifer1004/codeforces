n = int(input())
s = input()
dp = [[None for i in range(n + 1)] for i in range(n + 1)]
dp[0][0] = ('', '0', '0')
for i in range(1, n * 2 + 1):
    for j in range(max(0, i - n), min(i, n) + 1):
        k = i - j
        curr = -1
        if j > 0:
            choices, h, m = dp[j - 1][k]
            choices += 'H'
            if len(h) < j:
                h += s[i - 1]
            else:
                tmp = [c for c in h]
                tmp[j - 1] = s[i - 1]
                h = ''.join(tmp)
            if len(m) < j:
                m += '0'
            sum = int(h) + int(m)
            if sum > curr:
                curr = sum
                dp[j][k] = (choices, h, m)
        if k > 0:
            choices, h, m = dp[j][k - 1]
            choices += 'M'
            if len(m) < k:
                m += s[i - 1]
            else:
                tmp = [c for c in m]
                tmp[k - 1] = s[i - 1]
                m = ''.join(tmp)
            if len(h) < k:
                h += '0'
            sum = int(h) + int(m)
            if sum > curr:
                curr = sum
                dp[j][k] = (choices, h, m)
print(dp[n][n][0])

def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    cnt = [0 for i in range(26)]
    ps = [[0 for j in range(n + 1)] for i in range(26)]
    pt = [[0 for j in range(n + 1)] for i in range(26)]
    s = input()
    t = input()
    for i in range(n):
        ch = ord(s[i]) - ord('a')
        cnt[ch] += 1
        for j in range(26):
            ps[j][i + 1] = ps[j][i] + (1 if ch == j else 0)
    for i in range(n):
        ch = ord(t[i]) - ord('a')
        cnt[ch] -= 1
        for j in range(26):
            pt[j][i + 1] = pt[j][i] + (1 if ch == j else 0)
    ok = True
    for i in cnt:
        if i != 0:
            ok = False
            break
    if not ok:
        print(-1)
    else:
        r = n
        while r >= 1 and s[r - 1] == t[r - 1]:
            r -= 1
        inf = int(1e8)
        dp = [[0 if i == 0 else inf for j in range(
            r + 1)] for i in range(r + 1)]
        for i in range(1, r + 1):
            for j in range(i, r + 1):
                if s[i - 1] == t[j - 1]:
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1])
                ch = ord(t[j - 1]) - ord('a')
                if ps[ch][r] - ps[ch][i] > pt[ch][r] - pt[ch][j]:
                    dp[i][j] = min(dp[i][j], dp[i][j - 1])
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1)
        print(dp[r][r])

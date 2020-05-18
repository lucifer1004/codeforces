def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    p = []
    for i in range(n):
        ai, bi = read_ints()
        p.append((bi, ai, i + 1))
    p.sort()
    dp = [[0 for j in range(k + 1)] for i in range(n + 1)]
    use = [[False for j in range(k + 1)] for i in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(min(i, k) + 1):
            if i - 1 >= j:
                dp[i][j] = dp[i - 1][j] + (k - 1) * p[i - 1][0]
            if j > 0:
                x = dp[i - 1][j - 1] + (j - 1) * p[i - 1][0] + p[i - 1][1]
                if x > dp[i][j]:
                    dp[i][j] = x
                    use[i][j] = True
    used = []
    curr = k
    for i in range(n, 0, -1):
        if use[i][curr]:
            used.append(p[i - 1][2])
            curr -= 1
    used.reverse()
    seq = used[:-1]
    st = set(used)
    for i in range(1, n + 1):
        if not i in st:
            seq.append(i)
            seq.append(-i)
    seq.append(used[-1])
    print(len(seq))
    print(' '.join(map(str, seq)))

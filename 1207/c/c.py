t = int(input())
inf = int(1e18)
for case_num in range(t):
    n, a, b = map(int, input().split(' '))
    s = input() + '0'
    f = [0] * (n + 1)
    f[0] = b
    g = [0] * (n + 1)
    g[0] = inf
    for i in range(n):
        g[i + 1] = min(f[i] + 2 * a, g[i] + a) + 2 * b
        f[i + 1] = min(f[i] + a, g[i] + 2 * a) + \
            b if s[i] == '0' and s[i + 1] == '0' else inf
    print(f[n])

def fexp(x, y, mod):
    ans = 1
    while y > 0:
        if y % 2 == 1:
            ans = ans * x % mod
        x = x * x % mod
        y //= 2
    return ans


n, m = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
if m == 1:
    print(0)
else:
    a.sort()
    for i in range(n):
        a[i] %= m
    cnt = [0 for i in range(m)]
    delta = [0 for i in range(m)]
    for i in range(n):
        for j in range(m):
            if cnt[j] > 0:
                delta[(a[i] + m - j) % m] += cnt[j]
        cnt[a[i]] += 1
    ans = 1
    for i in range(m):
        ans = ans * fexp(i, delta[i], m) % m
    print(ans)

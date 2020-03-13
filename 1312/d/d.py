mod = 998244353


def fexp(x, y):
    ans = 1
    while y > 0:
        if y % 2 == 1:
            ans = ans * x % mod
        x = x * x % mod
        y //= 2
    return ans


maxn = 200005
fac = [1]
for i in range(maxn):
    fac.append(fac[-1] * (i + 1) % mod)
rev = [fexp(fac[i], mod - 2) for i in range(maxn + 1)]


def c(n, k):
    return 0 if n < k else fac[n] * rev[k] * rev[n - k] % mod


n, m = map(int, input().split(' '))
ans = 0
for k in range(n - 1, m + 1):
    cnt = c(k - 1, n - 2) * (n - 2) * fexp(2, n - 3) % mod
    ans = (ans + cnt) % mod
print(ans)

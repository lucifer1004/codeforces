mod = 998244353
fac = [1]
for i in range(1, 2001):
    fac.append(fac[-1] * i % mod)


def fexp(x, y):
    ans = 1
    while y > 0:
        if y % 2 == 1:
            ans = ans * x % mod
        x = x * x % mod
        y //= 2
    return ans


def rev(x):
    return fexp(x, mod - 2)


def c(n, k):
    return fac[n] * rev(fac[n - k]) * rev(fac[k]) % mod


n, m, k = map(int, input().split(' '))
print(c(n - 1, k) * m * fexp(m - 1, k) % mod)

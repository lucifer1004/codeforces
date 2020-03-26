mod = 998244353
n = int(input())
ten = [1]
for i in range(n):
    ten.append(ten[-1] * 10 % mod)
ans = [0] * n
ans[n - 1] = 10
for l in range(1, n):
    s = 2 * 10 * 9 * ten[n - l - 1]
    if n - l >= 2:
        s += (n - l - 1) * 10 * 81 * ten[n - l - 2]
    ans[l - 1] = s % mod
print(' '.join(map(str, ans)))

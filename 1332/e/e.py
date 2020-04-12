mod = 998244353


def fexp(x, y):
    ans = 1
    while y > 0:
        if y % 2 == 1:
            ans = ans * x % mod
        x = x * x % mod
        y //= 2
    return ans


n, m, l, r = map(int, input().split(' '))
half = (r - l + 1) // 2
odd = half
even = half
if l % 2 == 0 and r % 2 == 0:
    even += 1
if l % 2 == 1 and r % 2 == 1:
    odd += 1

# Cell number is odd, must be odd-only or even-only
if n * m % 2 == 1:
    ans = (fexp(r - l + 1, n * m)) % mod
    print(ans)
else:
    ans = (fexp(r - l + 1, n * m) + (0 if odd == even else 1)) * \
        fexp(2, mod - 2) % mod
    print(ans)

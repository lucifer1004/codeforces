n, l, r = map(int, input().split(' '))
lo = 2 ** l - 1 + n - l
hi = 2 ** r - 1 + (n - r) * (2 ** (r - 1))
print(lo, hi)

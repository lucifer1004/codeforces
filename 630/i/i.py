def fexp(a, b):
    ans = 1
    while b > 0:
        if b % 2 == 1:
            ans *= a
        a *= a
        b //= 2
    return ans


n = int(input())
mid = (n - 3) * 9 * fexp(4, n - 3)
side = 6 * fexp(4, n - 2)
print(mid + side)

def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


fac = [1]
rev = []
mod = 998244353


def fexp(x, y):
    ans = 1
    while y > 0:
        if y % 2 == 1:
            ans = ans * x % mod
        x = x * x % mod
        y //= 2
    return ans


def comb(n, k):
    return fac[n] * rev[k] * rev[n - k] % mod


n, k = read_ints()
if k >= n:
    print(0)
else:
    for i in range(1, n + 5):
        fac.append(fac[-1] * i % mod)
    for i in range(n + 5):
        rev.append(fexp(fac[i], mod - 2))
    # If there are no pairs being able to attack each other, all rooks must have unique rows and columns, thus there will be n! ways to assign them.
    if k == 0:
        print(fac[n])
    else:
        # Since the rooks need to be able to attack all empty cells, they either take up all rows, or all columns. Due to symmetry, we can only consider the first case, in which there is exactly one rook in each row.
        # There should be k empty columns, since each empty column contributes 1 pair.
        # There are C(n, k) ways to choose these columns.
        ways = comb(n, k)
        # Then we need to assign n rooks in the remaining n-k columns, and each column should have at least one rook.
        # This can be solved with inclusion-exclusion.
        # ans = \sum(-1)^i * C(n-k,i) * (n-k-i)^n
        # Here i means the minimum number of empty columns.
        col = 0
        for i in range(n - k):
            sign = 1 if i % 2 == 0 else -1
            col += sign * comb(n - k, i) * fexp(n - k - i, n)
            col %= mod
            if col < 0:
                col += mod
        # We need to times 2, since we only consider row situation for now.
        print(ways * col * 2 % mod)

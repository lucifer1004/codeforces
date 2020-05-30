def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, m, k = read_ints()
    hi = min(m, n // k)
    rest = (m - hi - 1) // (k - 1) + 1
    print(hi - rest)

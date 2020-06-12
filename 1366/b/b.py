def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, x, m = read_ints()
    lo = x
    hi = x
    for i in range(m):
        l, r = read_ints()
        if min(r, hi) >= max(lo, l):
            lo = min(lo, l)
            hi = max(hi, r)
    print(hi - lo + 1)

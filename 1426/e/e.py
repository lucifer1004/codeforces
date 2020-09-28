from itertools import permutations


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


n = read_int()
a = list(read_ints())
b = list(read_ints())
hi = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0])
lo = n
prs = [(0, 0), (0, 1), (1, 1), (1, 2), (2, 2), (2, 0)]
for seq in permutations(prs):
    a1 = a.copy()
    b1 = b.copy()
    no_win = 0
    for pr in seq:
        ai = pr[1]
        bi = pr[0]
        delta = min(a1[ai], b1[bi])
        no_win += delta
        a1[ai] -= delta
        b1[bi] -= delta
    lo = min(lo, n - no_win)
print(lo, hi)

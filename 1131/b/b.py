def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


n = read_int()
ans = 1
a = 0
b = 0
used = set([0])
for i in range(n):
    ai, bi = read_ints()
    hi = min(ai, bi)
    lo = max(a, b)
    if hi >= lo:
        ans += max(0, hi - lo - 1)
        if not hi in used:
            ans += 1
            used.add(hi)
        if not lo in used:
            ans += 1
            used.add(lo)
    a, b = ai, bi
print(ans)

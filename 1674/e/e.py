from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


n = read_int()
a = [int(1e9)] + list(read_ints()) + [int(1e9)]
sa = sorted(a)
ans = (sa[0] + 1) // 2 + (sa[1] + 1) // 2
for i in range(1, n + 1):
    if a[i - 1] % 2 == 1 and a[i + 1] % 2 == 1:
        ans = min(ans, a[i - 1] // 2 + a[i + 1] // 2 + 1)
    hi = max(a[i], a[i + 1])
    lo = min(a[i], a[i + 1])
    first = min(hi - lo, (hi + 1) // 2, lo)
    hi -= first * 2
    lo -= first
    curr = first
    if lo <= 0:
        curr += (hi + 1) // 2
    else:
        assert(hi == lo)
        if hi % 3 == 0:
            curr += hi // 3 * 2
        elif hi % 3 == 1:
            curr += hi // 3 * 2 + 1
        else:
            curr += (hi + 1) // 3 * 2
    ans = min(ans, curr)

print(ans)

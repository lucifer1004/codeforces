from functools import lru_cache


@lru_cache(maxsize=None)
def solve(a, b, c):
    ans = 0
    if a > 0:
        ans += 1
        a -= 1
    if b > 0:
        ans += 1
        b -= 1
    if c > 0:
        ans += 1
        c -= 1
    if b > 0 and c > 0:
        ans += 1
        b -= 1
        c -= 1
    if a > 0 and c > 0:
        ans += 1
        a -= 1
        c -= 1
    if a > 0 and b > 0:
        ans += 1
        a -= 1
        b -= 1
    if a > 0 and b > 0 and c > 0:
        ans += 1
        a -= 1
        b -= 1
        c -= 1
    return ans


t = int(input())
for case_num in range(t):
    items = list(map(int, input().split(' ')))
    items.sort()
    a, b, c = items
    print(solve(a, b, c))

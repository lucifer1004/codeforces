from sys import stdin
from collections import Counter
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    cnt = Counter(input())

    pairs = 0
    for key in cnt:
        pairs += cnt[key] // 2

    def check_odd(odd, k):
        if odd * k > n or pairs < odd // 2 * k:
            return False
        return True

    lo = 1
    hi = n // k
    while lo <= hi:
        mid = (lo + hi) // 2
        odd = mid * 2 - 1
        if check_odd(odd, k):
            lo = mid + 1
        else:
            hi = mid - 1

    ans = max(hi * 2 - 1, pairs // k * 2)
    print(ans)

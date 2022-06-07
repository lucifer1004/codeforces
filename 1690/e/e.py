from sys import stdin
from collections import Counter
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    a = list(read_ints())
    ans = sum(ai // k for ai in a)
    b = Counter(ai % k for ai in a)
    rem = 0
    r = 0
    for i in range(k - 1, 0, -1):
        if b[i] > 0 and rem > 0:
            b[i] -= 1
            if rem + i >= k:
                ans += 1
            rem = 0
        if b[i] == 0:
            continue

        while b[i] > 0 and r < i:
            while (b[r] == 0 and r < i) or r + i < k:
                r += 1
            if r < i and r + i >= k:
                pr = min(b[r], b[i])
                b[r] -= pr
                b[i] -= pr
                ans += pr

        if i * 2 >= k:
            ans += b[i] // 2
        b[i] %= 2
        if b[i] == 1:
            rem = i
    print(ans)

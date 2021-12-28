from sys import stdin
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    a = list(read_ints())
    if n == 1:
        print(max(0, a[0] - k))
        continue

    s = sum(a)
    if s <= k:
        print(0)
        continue

    a.sort()
    ans = s - k
    acc = 0
    for i, num in enumerate(a[::-1][:-1]):
        acc += num
        if acc - a[0] * (i + 1) >= s - k:
            ans = min(ans, i + 1)
            break
        d = (s - k + a[0] * (i + 1) - acc - 1) // (i + 2) + 1
        ans = min(ans, d + i + 1)
    print(ans)

from sys import stdin
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    h = list(read_ints())

    def check(lb):
        p = list(h)
        for i in range(n - 1, -1, -1):
            if p[i] < lb:
                return False

            if i >= 2:
                d = min(h[i] // 3, (p[i] - lb) // 3)
                p[i - 1] += d
                p[i - 2] += d * 2

        return True

    lo = 0
    hi = sum(h) // n
    while lo <= hi:
        mid = (lo + hi) >> 1
        if check(mid):
            lo = mid + 1
        else:
            hi = mid - 1

    print(hi)

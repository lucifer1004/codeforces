from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    a = list(read_ints())
    ans = 0
    acc = 0
    for i in range(1, n):
        if a[i] * 2 > a[i - 1]:
            acc += 1
        else:
            acc = 0
        if acc >= k:
            ans += 1
    print(ans)

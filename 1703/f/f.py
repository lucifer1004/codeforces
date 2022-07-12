from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    ans = 0
    left = [0] * (n + 1)  # left[i] means valid count in first i numbers
    for i in range(n):
        left[i + 1] = left[i]
        if a[i] < i + 1:
            left[i + 1] += 1
    for i in range(n):
        if 0 < a[i] < i + 1:
            ans += left[a[i] - 1]
    print(ans)

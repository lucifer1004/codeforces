from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    s = input()
    ans = n
    wcnt = 0
    for i, ch in enumerate(s):
        if ch == 'W':
            wcnt += 1
        if i >= k and s[i - k] == 'W':
            wcnt -= 1
        if i >= k - 1:
            ans = min(ans, wcnt)
    print(ans)

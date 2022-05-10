from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


def diff(s, t):
    ans = 0
    for p, q in zip(s, t):
        a = ord(p) - ord('a')
        b = ord(q) - ord('a')
        ans += max(a, b) - min(a, b)
    return ans


t = read_int()
for case_num in range(t):
    n, m = read_ints()
    s = [input() for _ in range(n)]
    ans = int(1e9)
    for i in range(n):
        for j in range(i + 1, n):
            ans = min(ans, diff(s[i], s[j]))
    print(ans)

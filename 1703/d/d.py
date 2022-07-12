from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    s = [input() for _ in range(n)]
    st = set(s)
    ans = [0] * n
    for i in range(n):
        m = len(s[i])
        for k in range(1, m):
            if s[i][:k] in st and s[i][k:] in st:
                ans[i] = 1
                break
    print(''.join(map(str, ans)))

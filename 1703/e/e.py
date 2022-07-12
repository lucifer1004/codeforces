from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    a = [list(map(int, input())) for _ in range(n)]
    ans = 0
    for i in range(n // 2):
        for j in range((n + 1) // 2):
            cnt = a[i][j] + a[j][n - 1 - i] + \
                a[n - 1 - i][n - 1 - j] + a[n - 1 - j][i]
            ans += min(cnt, 4 - cnt)
    print(ans)

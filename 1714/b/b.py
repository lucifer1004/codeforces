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
    s = set()
    ans = 0
    for i in range(n - 1, -1, -1):
        if a[i] in s:
            ans = i + 1
            break
        s.add(a[i])
    print(ans)

from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    s = input()
    special = input().split()[1:]
    svec = [False] * 26
    for ch in special:
        svec[ord(ch) - ord('a')] = True
    x = [i for i, ch in enumerate(s) if svec[ord(ch) - ord('a')]]
    last = 0
    ans = 0
    for i in x:
        ans = max(ans, i - last)
        last = i
    print(ans)

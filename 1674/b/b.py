from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    s = input()
    a = ord(s[0]) - ord('a')
    b = ord(s[1]) - ord('a')
    ans = a * 25 + b
    if s[1] < s[0]:
        ans += 1
    print(ans)

from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    input()
    s = [input() for _ in range(8)]
    found = False
    for i in range(1, 7):
        for j in range(1, 7):
            if s[i][j] == s[i - 1][j - 1] == s[i - 1][j + 1] == s[i + 1][j - 1] == s[i + 1][j + 1] == '#':
                print(i + 1, j + 1)
                found = True
                break
        if found:
            break

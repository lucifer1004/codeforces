from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    s = read_int()
    ans = []
    for i in range(9, 0, -1):
        if s >= i:
            s -= i
            ans.append(i)
    print(''.join(map(str, ans[::-1])))

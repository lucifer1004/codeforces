from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    s = input()
    cnt = 1
    mem = set()
    for si in s:
        if si not in mem:
            if len(mem) == 3:
                mem = set()
                cnt += 1
            mem.add(si)
    print(cnt)

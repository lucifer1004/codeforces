from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
d = [0]
c = 0
while d[-1] < int(2e9):
    d.append(d[-1] + c)
    d.append(d[-1] + c + 2)
    d.append(d[-1] + c + 4)
    c += 4


for case_num in range(t):
    n = read_int()
    lo = 2
    hi = 100000
    while lo <= hi:
        mid = (lo + hi) >> 1
        if d[mid] >= n:
            hi = mid - 1
        else:
            lo = mid + 1
    print(lo)

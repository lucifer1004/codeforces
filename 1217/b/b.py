import math

t = int(input())
for case_num in range(t):
    n, x = map(int, input().split(' '))
    d = []
    h = []
    delta = []
    for i in range(n):
        di, hi = map(int, input().split(' '))
        d.append(di)
        h.append(hi)
        delta.append(di - hi)
    md = max(d)
    mdelta = max(delta)
    if md < x and mdelta <= 0:
        print(-1)
    else:
        if md >= x:
            print(1)
        else:
            print(max(0, math.ceil((x - md) / mdelta)) + 1)

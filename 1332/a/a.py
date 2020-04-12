t = int(input())
for case_num in range(t):
    a, b, c, d = map(int, input().split(' '))
    x, y, x1, y1, x2, y2 = map(int, input().split(' '))
    ok = True
    if a > b:
        delta = a - b
        if x - x1 < delta:
            ok = False
    elif a == b and a > 0:
        if x == x1 and x == x2:
            ok = False
    else:
        delta = b - a
        if x2 - x < delta:
            ok = False

    if c > d:
        delta = c - d
        if y - y1 < delta:
            ok = False
    elif c == d and c > 0:
        if y == y1 and y == y2:
            ok = False
    else:
        delta = d - c
        if y2 - y < delta:
            ok = False

    print('Yes' if ok else 'No')

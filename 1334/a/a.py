t = int(input())
for case_num in range(t):
    n = int(input())
    lastp = 0
    lastc = 0
    ok = True
    for i in range(n):
        p, c = map(int, input().split(' '))
        if p < lastp or c < lastc or p - lastp < c - lastc:
            ok = False
        lastp = p
        lastc = c
    print('YES' if ok else 'NO')

t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    b = list(map(int, input().split(' ')))
    pos = False
    neg = False
    ok = True
    for i in range(n):
        if (not pos) and (not neg) and (a[i] != b[i]):
            ok = False
            break
        if (not pos) and (a[i] < b[i]):
            ok = False
            break
        if (not neg) and (a[i] > b[i]):
            ok = False
            break
        if a[i] < 0:
            neg = True
        if a[i] > 0:
            pos = True
    print('YES' if ok else 'NO')

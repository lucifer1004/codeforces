t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    a.append(a[0])
    delta = (a[0] + n - a[1]) % n
    ok = True
    if delta != 1 and delta != n - 1:
        ok = False
    if ok:
        for i in range(1, n):
            if (a[i] + n - a[i + 1]) % n != delta:
                ok = False
                break
    print('YES' if ok else 'NO')

t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    a.sort()
    ok = True
    for i in range(n - 1):
        if a[i + 1] - a[i] == 1:
            ok = False
            break
    print(1 if ok else 2)

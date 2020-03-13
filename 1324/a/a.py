t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    a.sort()
    ok = True
    for i in range(n-1):
        if (a[i + 1] - a[i]) % 2 != 0:
            ok = False
            break
    print("YES" if ok else "NO")

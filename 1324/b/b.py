t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    first = dict()
    ok = False
    for i in range(n):
        if a[i] in first:
            if i - first[a[i]] >= 2:
                ok = True
                break
        else:
            first[a[i]] = i
    print("YES" if ok else "NO")

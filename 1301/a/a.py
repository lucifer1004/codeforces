t = int(input())
for case_num in range(t):
    a = input()
    b = input()
    c = input()
    ok = True
    for i in range(len(a)):
        if a[i] != c[i] and b[i] != c[i]:
            ok = False
            break
    print("YES" if ok else "NO")

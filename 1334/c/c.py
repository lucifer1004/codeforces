t = int(input())
for case_num in range(t):
    n = int(input())
    a = []
    b = []
    for i in range(n):
        ai, bi = map(int, input().split(' '))
        a.append(ai)
        b.append(bi)
    rest = []
    for i in range(n):
        rest.append(max(a[i] - b[(i - 1 + n) % n], 0))
    s = sum(rest)
    ans = int(1e18)
    for i in range(n):
        ans = min(ans, s - rest[i] + a[i])
    print(ans)
